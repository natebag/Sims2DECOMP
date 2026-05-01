// asm-processor PARKED — 0x8027AB3C AptActionInterpreter::_FunctionAptActionStackSwap (112B).
//
// DIAGNOSIS (2026-04-21, OpusWorker, S13 Phase 3 batch):
// 16 mismatched bytes across 6 distinct diff regions. Not a clean fp_relabel
// or gpr_relabel case — the difference is a mix of (a) INDEPENDENT register
// swaps on different instructions (not a single consistent rotation) and
// (b) an actual instruction-pair REORDER at offset 0x10-0x14.
//
// Diff summary:
//   off 0x04:  DOL `lwz r0, 8(r3)`          SN `lwz r11, 8(r3)`       (stack base: r0 vs r11)
//   off 0x10:  DOL `slwi r11, r8, 2`        SN `add r9, r11, r9`      (REORDER pair)
//   off 0x14:  DOL `add r9, r9, r0`         SN `slwi r0, r8, 2`       (REORDER pair)
//   off 0x44:  DOL `lwz r10, 8(r3)`         SN `lwz r11, 8(r3)`       (stack base: r10 vs r11)
//   off 0x48:  DOL `slwi r11, r9, 2`        SN `slwi r0, r9, 2`       (scaled-index)
//   off 0x4c:  DOL `stwx r7, r11, r10`      SN `stwx r7, r11, r0`     (rB diff)
//   off 0x58:  DOL `slwi r10, r9, 2`        SN `slwi r0, r9, 2`       (scaled-index, different reg than 0x48)
//   off 0x64:  DOL `stwx r6, r10, r11`      SN `stwx r6, r11, r0`     (rA + rB swap)
//
// Needed directives (no single existing mutator covers all of them):
//   - swap_adj on the 0x10/0x14 instruction-pair reorder (slwi<->add)
//     — CURRENT swap_adj only swaps two lines if their opcodes match a
//       specified (a,b) pair. The reorder here is (slwi, add) -> (add, slwi),
//       but the registers also change post-swap. swap_adj leaves the
//       lines unchanged otherwise; the post-swap registers of the swapped
//       lines don't match DOL either, so additional register fixup needed.
//   - gpr_relabel is unsuitable: DOL picks r0 at 0x04 (vs r11), r10 at 0x44
//     (vs r11), and r11 at 0x48 (vs r0) — three independent swaps that
//     cannot be expressed as one bidirectional swap map.
//   - force_reg on each individual line works but would need ~8 directives.
//     Given the PushStringDictByte precedent (3-directive force_reg chain
//     matched), this is probably the fastest path.
//
// Estimated complexity: ~8-10 force_reg directives + possibly 1 swap_adj
// for the 0x10/0x14 reorder. ~30-45 min of directive authoring + iteration.
//
// Alternative: source-level nudge to get GCC to choose DOL's allocation —
// unlikely given the structural nature of the reg diffs (register pressure
// across the conditional branch is probably why GCC picks r11 repeatedly).
//
// PARKED for future session / SonnetWorker2 pickup. No directive applied.
//
// 2026-05-01 PROOF-OF-CONCEPT (OpusWorker, S13 task 1752588a):
// Verified that `// ASMPROC_swap_adj: a=add b=slwi which=first` cleanly
// resolves the 0x010-0x014 instruction reorder. Post-swap_adj:
//   0x010: slwi r0,r8,2  (was at 0x014 — correct position now)
//   0x014: add  r9,r11,r9 (was at 0x010 — correct position now)
//
// Reduces diff from 8 → 6 offsets but introduces new structural blocker:
// the post-swap `add r9,r11,r9` has rA/rB transposed vs DOL's `add r9,r9,r0`.
// Even with gpr_relabel 11↔0 to fix register coloring, the OPERAND ORDER
// inside the add stays SN's (rD=r9,rA=r0,rB=r9 post-relabel) vs DOL's
// (rD=r9,rA=r9,rB=r0). add is semantically commutative but the byte encoding
// differs.
//
// Remaining required mutators (none currently in arsenal):
//   - `swap_operands match=<line> rA<->rB` — for the add at post-swap 0x014
//   - 5-7 force_reg directives for the per-site GPR coloring mismatches
//     (0x004 r11→r0, 0x044 r11→r10, 0x048 r0→r11, 0x04c stwx rB swap,
//      0x058 r0→r10, 0x064 stwx rA/rB swap)
//
// Cleanest forward path:
//   1. Author `swap_operands` mutator (matches a line, swaps two operand
//      positions identified by index — generalizes the rA↔rB pattern)
//   2. Apply: swap_adj a=add b=slwi which=first
//      + swap_operands match="add 9,11,9" pos=2,3
//      + 7 force_reg directives at the listed sites
//   3. Iterate the directive set to convergence
//
// Without `swap_operands`, alternative: gpr_relabel-then-source-coax to
// achieve the operand order naturally. Open question for OpusReviewGuy.

typedef unsigned char u8;

struct AptActionInterpreter {
    int m_stackIdx;
    char pad_04[4];
    u8** m_stack;

    struct LocalContextT { int* m_pc; };

    static void _FunctionAptActionStackSwap(AptActionInterpreter* interp,
                                             LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionStackSwap(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    (void)ctx;
    int sp = interp->m_stackIdx;
    u8** stack = interp->m_stack;
    int spMinus1 = sp - 1;
    int sp4 = sp << 2;
    int sp4m1 = spMinus1 << 2;

    u8* v1 = *(u8**)((char*)stack + sp4 - 4);
    u8* v2 = *(u8**)((char*)stack + sp4m1 - 4);

    if (sp > 0) {
        interp->m_stackIdx = spMinus1;
        if (spMinus1 > 0) {
            interp->m_stackIdx = spMinus1 - 1;
        }
    }

    int sp2 = interp->m_stackIdx;
    u8** stack2 = interp->m_stack;
    *(u8**)((char*)stack2 + (sp2 << 2)) = v1;
    sp2 = sp2 + 1;
    interp->m_stackIdx = sp2;

    u8** stack3 = interp->m_stack;
    *(u8**)((char*)stack3 + (sp2 << 2)) = v2;
    sp2 = sp2 + 1;
    interp->m_stackIdx = sp2;
}
