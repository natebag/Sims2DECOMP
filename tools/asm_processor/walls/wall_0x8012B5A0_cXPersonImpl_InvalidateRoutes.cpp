// ASMPROC_insert_mr: after=bclr src=11 dst=3 relabel=10:11,11:3
// asm-processor PARKED — 0x8012B5A0 cXPersonImpl::InvalidateRoutes (52B).
//
// DIAGNOSIS (2026-04-21, OpusWorker Phase 2):
// SIZE_MISMATCH (DOL=52B, SN=48B). This is a STRUCTURAL wall, not operand-level.
//
// DOL uses 13 insns with a `mr r3,r11` + `li r11,0` pattern that reuses r11
// as the zero-store constant while aliasing r3 to the base pointer.
// SN uses 12 insns with r10 as the zero constant, keeping r11 live as base.
//
// 2026-05-01 RE-VERIFICATION (OpusWorker, S13 task 1752588a):
// 7 source-level rewrite attempts confirm the structural classification.
// Closest near-match was v4 (base = &m_start; base[0]/base[1] entry +
// base[1] re-read in loop) which produced this exact shape:
//
//     0x00: addi r11,r3,1036  ✓ matches DOL
//     0x04: lwz  r9,1036(r3)  ✓
//     0x08: lwz  r0,4(r11)    ✓
//     0x0c: cmpw r9,r0        ✓
//     0x10: beqlr             ✓
//     0x14: li   r10,0        ✗ DOL has `mr r3,r11` here (extra insn)
//     0x18: stw  r10,124(r9)  ✗ DOL uses r11 for the zero
//     0x1c: addi r9,r9,164    ✓
//     0x20: lwz  r0,4(r11)    ✗ DOL uses r3 (post-mr-rename)
//     0x24: cmpw r9,r0        ✓
//     0x28: bne  -loop        ✓
//     0x2c: blr               ✓
//
// 12 of 13 insns match. The single missing insn (`mr r3,r11`) is a
// register-renaming decision GCC's allocator declines to make from any
// natural source structure — DOL inserts it precisely to free r11 as the
// zero-store reg, but only after tracking that r11 will be needed for
// frequent stores in the loop. SN's RA cost model picks r10 instead and
// avoids the rename entirely.
//
// Tried (all fail to insert the mr):
//   (a) Plain while-loop with >= / <                           → 48B
//   (b) do-while-after-guard with == / !=                      → 44B
//   (c) base = &m_start cached, base[0]/base[1] both reads     → 44B
//   (d) for-loop with m_start / m_end                          → 44B
//   (e) hybrid base[1] entry + this re-read                    → 44B
//   (f) byte-pointer base = (char*)this + 0x40C                → 44B
//   (g) base[0]/base[1] entry + base[1] loop re-read           → 48B (closest)
//
// Existing mutators don't fit:
//   - swap_adj: only swaps two same-opcode lines (no insert)
//   - gpr_relabel: only relabels existing regs (no insert)
//   - force_reg: only forces specific reg on existing insn (no insert)
//   - fp_relabel: FP-only
//
// Required mutator: NEW `insert_mr` (or general `insert_insn`) that adds
// an instruction at a specific offset and rewrites subsequent register
// references in a delimited region. Non-trivial — needs label-tracking
// across the inserted insn for the relocation entries.
//
// PARKED for Phase 3 design review with OpusReviewGuy. Recommend:
//   1. Author `insert_mr <offset> <src_reg> <dst_reg>` mutator
//   2. Author `relabel_range <from_offset> <to_offset> <swap_map>` mutator
//   3. Apply: insert_mr 0x14 r11 r3, then relabel_range 0x14:0x2c r11:r3 r10:r11

struct RouteNode {
    char pad[0x7C];
    int field_7C;
    char pad2[0x24];
};

struct cXPersonImpl {
    char pad[0x40C];
    RouteNode* m_start;
    RouteNode* m_end;
    void InvalidateRoutes();
};

void cXPersonImpl::InvalidateRoutes() {
    RouteNode** base = &m_start;
    RouteNode* p = base[0];
    if (p == base[1]) return;
    do {
        p->field_7C = 0;
        p++;
    } while (p != base[1]);
}
