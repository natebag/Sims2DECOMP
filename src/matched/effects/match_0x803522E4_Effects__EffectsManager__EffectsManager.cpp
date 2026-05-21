// 0x803522E4 Effects::EffectsManager::EffectsManager(void) (52B)
//
// 4TH INSTANCE — PROMOTES `uniform-volatile-int-ctor` recipe from
// 3-INSTANCE-CANDIDATE to STANDARD.
//
// Variant adds **sub-base pointer** pattern (char* sub4 = base + 4 +
// char* sub16 = base + 16) on top of the original 4-directive recipe.
// Forces DOL's `addi r11, r9, 4; addi r10, r9, 16` intermediate-base-
// pointer emission instead of GCC's direct `stw r0, 8(r9)` form.
//
// Pure source-only crack (no mutator directives):
//   1. Uniform `*(volatile int*)` cast for all stores.
//   2. Explicit sub-base pointer locals (sub4, sub16) to force the addi
//      intermediate-base computations DOL emits.
//   3. Anchor stores (m_0, m_4, m_16) via base ptr; neighbor stores
//      (m_8, m_12 via sub4; m_20, m_24 via sub16) via the sub-base.
//
// Recipe family now STANDARD — applies to:
//   - Direct uniform-volatile-int ctors (REffectsEmitter, ERSoundTrackData,
//     ERAmbientScore — 3-instance variant)
//   - Sub-base ptr variant (EffectsManager — 4th instance) — this commit
//
// Replaces earlier BROKEN match at same path (was SIZE_MISMATCH against
// DOL). Per MainGuy authorization 2026-05-21 (escalation protocol).

namespace Effects {

class EffectsManager {
public:
    EffectsManager();
};

EffectsManager::EffectsManager() {
    char* base = (char*)this;
    *(volatile int*)(base + 0) = 0;        // m_0 via base
    char* sub4 = base + 4;
    *(volatile int*)(sub4 + 4) = 0;        // m_8 via sub4+4
    *(volatile int*)(base + 4) = 0;        // m_4 via base
    *(volatile int*)(sub4 + 8) = 1;        // m_12 via sub4+8
    char* sub16 = base + 16;
    *(volatile int*)(sub16 + 4) = 0;       // m_20 via sub16+4
    *(volatile int*)(base + 16) = 0;       // m_16 via base
    *(volatile int*)(sub16 + 8) = 1;       // m_24 via sub16+8
}

}
