// 0x803457B0 (88B) ENgcRenderer::QuadList(EDLEntry *)
// Lane N fallback target. VERSION_DIFF — Track-I scheduler wall (S13 2026-05-02).
//
// SIZE: matches 88B/88B. BYTES: MISMATCH at instruction-scheduling boundary.
//
// Divergence (mine vs DOL):
//   DOL @0x10..0x28:
//     mr   r9,r4         (preserve cmd into r9, freeing r4 for arg)
//     li   r11,1
//     lbz  r0,1(r9)      (m_flag)
//     lwz  r4,4(r9)      (count → r4 DIRECTLY — first arg slot)
//     cmpwi r0,0
//     bne  +8            (skip li r11,0)
//     li   r11,0
//     lwz  r10,28(r9)    (continues loads regardless of branch)
//     ...
//
//   Mine: cmpwi r0,0 BEFORE lwz r4,4(r9). bne offset becomes +0x24, skipping
//   the entire load block. Result: count load deferred, then `mr r4,r11` at
//   tail — extra instruction. Compiler refuses to schedule count load before
//   the cmpwi regardless of source ordering.
//
// Source-coercion attempts (4 variants — all hit scheduler wall):
//   v1: bool flag = cmd->m_flag != 0; passed as last arg
//       → bne+0x24 over loads, +mr at tail
//   v2: declared bool flag in temp before call (same as v1 logically)
//       → identical result
//   v3: cmd->m_flag ? true : false ternary inline at call
//       → loads scheduled early but count went to r11, then mr r4,r11 at tail
//   v4: aliased ptr `EDLEntry_QL* p = cmd;` then bool flag = p->m_flag != 0;
//       → identical to v1
//
// Root cause: GCC 2.95.3 SN ProDG scheduler refuses to place the count load
// before the m_flag cmpwi when count is just one of 7 ptr/int args. DOL's
// pattern requires count→r4 (1st arg slot) load before flag check; this needs
// the `mr r9,r4` preservation pattern, which GCC won't emit in this context.
//
// MutatorSmith candidate: register-rename / scheduler nudge mutator.
//   Pre-mutation anchor: cmpwi r0,0 immediately followed by bne (no count
//                        load between).
//   Post-mutation: insert `mr r9,r4` early; rewrite all subsequent cmd-deref
//                  loads to use r9 base; place lwz r4,4(r9) BEFORE cmpwi.
// Pattern resembles BP9 register-rename wall (r24..r31 vs r23..r31 saved).
//
// Class: ENgcRenderer EDLEntry-dispatcher subfamily. Sibling matches
// already exist (SpriteListPacked, ModelMatrixIndices) but those have
// fewer args and don't trigger this scheduler asymmetry.

struct EDLEntry_QL {
    char pad0[1];
    unsigned char m_flag;     // 1
    char pad2[2];
    int m_count;              // 4
    float* m_p8;              // 8
    float* m_p12;             // 12
    unsigned char* m_p16;     // 16
    signed char* m_p20;       // 20
    unsigned char* m_p24;     // 24
    unsigned char* m_p28;     // 28
};

struct ENgcRenderer_QL {
    void QuadList(EDLEntry_QL* cmd);
    void QuadList(int n, float* a, float* b, unsigned char* c, signed char* d,
                  unsigned char* e, unsigned char* f, bool flag);
};

void ENgcRenderer_QL::QuadList(EDLEntry_QL* cmd) {
    EDLEntry_QL* p = cmd;
    int count = p->m_count;
    bool flag = p->m_flag != 0;
    QuadList(count, p->m_p8, p->m_p12, p->m_p16, p->m_p20,
             p->m_p24, p->m_p28, flag);
}
