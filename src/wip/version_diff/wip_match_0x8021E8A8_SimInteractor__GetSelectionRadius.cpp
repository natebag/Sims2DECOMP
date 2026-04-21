// WIP PARTIAL-FAKE / WALL (moved from src/matched/ by S13 pre-session triage, 2026-04-21)
// Diagnostic: MISMATCH 64B: SimInteractor getter wall. Parked S12.
// Original path: src/matched/siminteractor/match_0x8021E8A8_SimInteractor__GetSelectionRadius.cpp
//
// 0x8021E8A8 (64B) InteractorModule::SimInteractor::GetSelectionRadius(void)

namespace InteractorModule {

extern float base_GetSelectionRadius();

struct SimInteractor {
    char pad[0x214];
    int m_field_214;  // +0x214 = 532
    float GetSelectionRadius();
};

float SimInteractor::GetSelectionRadius() {
    float result = base_GetSelectionRadius();
    if (m_field_214 == 0) {
        result = *(float*)0x803FDD1C;
    }
    return result;
}

} // namespace InteractorModule
