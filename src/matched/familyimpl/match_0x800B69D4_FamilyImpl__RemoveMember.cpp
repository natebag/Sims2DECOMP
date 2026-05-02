// 0x800B69D4 FamilyImpl::RemoveMember(int) (132B)
//
// First STANDARD-ship byte-match for the `force_reg_at_pos` mutator (Track I
// queue #4). cc1plus emits 32 inst / 128B with src materialized directly into
// r10 from the addi (`addi 10,9,4`) and m_end into r0 (`lwz 0,4(3)`). DOL
// materializes src into r0 first then explicitly moves it to r11 (`mr 11,0`)
// for the shift loop, and puts m_end into r8 (`lwz 8,4(3)`). DOL also orders
// the shift-prep block as (mr 11,0 ; mr 10,9 ; subf 0,11,8) where cc1plus
// emits (subf ; mr) without the inserted move.
//
// 7-directive recipe — pre-cascade + insert_mr + post-cascade position-aware
// fix. Multi-directive composition discipline: the post-insert match substring
// is authored against the POST-relabel state (r10↔r11 swap by insert_mr's
// relabel map turns `subf 0,10,0` into `subf 0,11,0`).
//
// Pre-cascade (4): force_reg×3 nudge cc1plus's register choices (r10→r0 on
// addi, r0→r8 on lwz, r10→r8 on cmpw) and swap_operands flips cmpw's
// rA/rB to match DOL's register order. swap_adj reorders the (subf ; mr)
// pair so the inserted `mr 11,0` sits between the existing `mr 11,9` and the
// (now reordered) `subf` line.
//
// Insert (1): insert_mr injects `mr 11,0` after the `# beq cr0` anchor and
// applies bidirectional relabel r10↔r11 from the inserted line through the
// first blr — converting `mr 11,9 → mr 10,9` and `subf 0,10,0 → subf 0,11,0`.
//
// Post-cascade (1): force_reg_at_pos targets pos=2 (ra) of the relabeled
// `subf 0, 11, 0` line, renaming r0 → r8 to match DOL's `subf 0,11,8`.
// Whole-line force_reg would clobber the r0 at pos=0 (rt); only force_reg_at_pos
// can change ra without touching rt.
//
// Validation: 7-directive recipe → asm_processor MATCH (132B byte-perfect).
//
// ASMPROC_force_reg: match="addi 10,9,4" from_reg=10 to_reg=0
// ASMPROC_force_reg: match="lwz 0,4(3)" from_reg=0 to_reg=8
// ASMPROC_swap_operands: match="cmpw 0,10,0" pos=1,2
// ASMPROC_force_reg: match="cmpw 0,0,10" from_reg=10 to_reg=8
// ASMPROC_swap_adj: a=subf b=mr which=first
// ASMPROC_insert_mr: after="# beq  cr0" src=0 dst=11 relabel=10:11,11:10
// ASMPROC_force_reg_at_pos: match="subf 0, 11, 0" pos=2 from_reg=0 to_reg=8

struct FamilyImpl {
    struct MemberVector {
        int* m_begin;
        int* m_end;
        int* m_capacity;
    };
    char pad[0x24];
    MemberVector m_members;

    void RemoveMember(int memberId);
};

void FamilyImpl::RemoveMember(int memberId) {
    MemberVector* mv = &m_members;
    int* begin = m_members.m_begin;
    if (begin == mv->m_end) return;

    do {
        if (*begin == memberId) {
            MemberVector* mv2 = &m_members;
            int* src = begin + 1;
            if (src != mv2->m_end) {
                int* dst = begin;
                int n = mv2->m_end - src;
                while (n > 0) {
                    *dst++ = *src++;
                    n--;
                }
            }
            mv2->m_end = mv2->m_end - 1;
            return;
        }
        begin++;
    } while (begin != mv->m_end);
}
