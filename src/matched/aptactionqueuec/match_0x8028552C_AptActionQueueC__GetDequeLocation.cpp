// 0x8028552C (80B) AptActionQueueC::GetDequeLocation(int) const
//
// First STANDARD-ship byte-match for the `region_gpr_relabel` mutator
// (Track I queue #3, S13 Session 4). cc1plus -O2 produces the DOL block
// layout natively after the `if (wrapped >= 0)` polarity flip — 7 residual
// mismatches at offsets 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x34, 0x44 collapse
// to a single post-cc1plus directed register-rename directive.
//
// Mismatch shape (all register-coloring, block layout identical):
//   - cc1plus colors the post-mullw `wrapped` intermediate r0 throughout.
//   - DOL transitions the value r0 -> r3 at the srawi (>>2) kill point and
//     reuses r0 for the divw quotient.
//   - srawi 0,0,2          -> srawi 3,0,2     (dest r0 -> r3)
//   - add 0,0,4            -> add 3,3,4
//   - divw 9,0,11          -> divw 0,3,11
//   - mullw 9,9,11         -> mullw 0,0,11
//   - subf. 0,9,0          -> subf. 3,0,3
//   - add 3,0,11           -> add 3,3,11
//   - mulli 3,0,20         -> mulli 3,3,20    (final region line)
//
// Resolution: `region_gpr_relabel` applies a directed `0:3,9:0` rename
// across the bounded region [srawi 0,0,2 .. mulli 3,0,20]. Start anchor
// uses default start_mode="at" semantics — only srawi's dest operand
// is renamed (the source operand reads r0 from outside the region's
// namespace and is preserved). End anchor included via default
// end_mode="at".
//
// Validation evidence: smoke tests pass 10/10 in
// `tools/asm_processor/mutators/test_region_gpr_relabel.py`.
// verify_match.sh: MATCH at 0x8028552C (80B).
//
// FLAGS: -msdata=eabi -G 8
// ASMPROC_region_gpr_relabel: start_anchor="srawi 0,0,2" end_anchor="mulli 3,0,20" rename="0:3,9:0"

struct DequeElement {
    char data[20];
};

struct AptActionQueueC {
    DequeElement* m_begin;
    DequeElement* m_tail;
    DequeElement* m_end;
    char pad[4];
    int m_capacity;

    DequeElement* GetDequeLocation(int idx) const;
};

DequeElement* AptActionQueueC::GetDequeLocation(int idx) const {
    int wrapped = (m_tail - m_begin) + idx;
    wrapped = wrapped % m_capacity;
    if (wrapped >= 0) {
        return m_begin + wrapped;
    }
    return m_begin + (wrapped + m_capacity);
}
