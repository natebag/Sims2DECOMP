// 0x800B69D4 (132B) FamilyImpl::RemoveMember(int)
// WALL: loop_body_equivalence — needs `loop_to_ptrwalk` mutator OR
//       SN ProDG scheduling-pattern coax (40-byte/10-instr residual after
//       triage-first source-level descope attempts).
//
// Source-level progress: 72B → 56B → 40B residual diff via three iterations:
//   1. Pointer-comparison while-loop → 192B compiled (72B short)
//   2. Count-based ptrdiff_t shift loop with do-while → 208B (56B short)
//   3. + explicit src==end shortcircuit before count → 224B (40B short)
//
// Why source-level alone can't close the last 40B:
//   - DOL sets up `r11 = &m_begin alias` (this+0x24) at function entry, then
//     accesses m_end via `r11+4`. Compiler then reuses r11 for src in shift
//     loop, requiring `addi r3, r3, 36` mid-function to reload m_end via r3+4.
//   - This dual-aliasing is a register-allocation choice, not source-driven.
//   - DOL also re-loads m_end TWICE in the function body (once at outer-iter
//     entry 0x70 via r11+4, once at decrement-block 0x60 via r3+4). My
//     compiled keeps m_end in r11 throughout — efficient but wrong shape.
//
// Recommended mutator: `loop_to_ptrwalk` (per dossier) — alternatively a
// `force_alias_base` mutator that converts `lwz rA, off(rThis)` patterns
// into `addi rB, rThis, off; lwz rA, 0(rB); ...; lwz rC, 4(rB)` patterns
// for member-access aliasing.

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
    int* begin = m_members.m_begin;
    int* end = m_members.m_end;
    if (begin == end) return;

    do {
        if (*begin == memberId) {
            int* src = begin + 1;
            if (src != end) {
                int* dst = begin;
                int n = end - src;
                while (n > 0) {
                    *dst++ = *src++;
                    n--;
                }
            }
            m_members.m_end = m_members.m_end - 1;
            return;
        }
        begin++;
    } while (begin != end);
}
