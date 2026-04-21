// asm-processor PARKED — 0x8012B5A0 cXPersonImpl::InvalidateRoutes (52B).
//
// DIAGNOSIS (2026-04-21, OpusWorker Phase 2):
// SIZE_MISMATCH (DOL=52B, SN=48B). This is a STRUCTURAL wall, not operand-level.
//
// DOL uses 13 insns with a `mr r3,r11` + `li r11,0` pattern that reuses r11
// as the zero-store constant while aliasing r3 to the base pointer.
// SN uses 12 insns with r10 as the zero constant, keeping r11 live as base.
//
// Tried:
//   (a) Plain while-loop (original source)                 → 48B
//   (b) do-while-after-guard restructure (below)           → 48B
//   (c) (not tried) explicit r3-use in loop body
//
// No source-level coaxing moves SN to the DOL's register-reuse strategy.
// It's a cost-model decision in GCC 2.95's register allocator.
//
// Candidate mutators:
//   - "insert_mr + relabel" structural mutator (non-trivial — would need to
//     insert a `mr r3,r11` after bgelr and rewrite subsequent r11 refs)
//   - Or SW2's gpr_relabel at the right swap spec (but size still mismatches)
//
// Escalated to Phase 3 design review with OpusReview. Not blocking Phase 3
// progress — other walls are more tractable via source-level or existing
// mutators.
// PARKED: no directive applied; keep_noop baseline compile only.

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
    RouteNode* p = *base;
    RouteNode* end = *(base + 1);
    if ((int)p >= (int)end) return;
    do {
        p->field_7C = 0;
        p++;
        end = *(base + 1);
    } while ((int)p < (int)end);
}
