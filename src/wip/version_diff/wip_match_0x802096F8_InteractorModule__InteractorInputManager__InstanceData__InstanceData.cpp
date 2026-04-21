// WIP PARTIAL-FAKE / WALL (moved from src/matched/ by S13 pre-session triage, 2026-04-21)
// Diagnostic: MISMATCH 52B: nested namespace ctor wall. Parked S12.
// Original path: src/matched/interactormodule/match_0x802096F8_InteractorModule__InteractorInputManager__InstanceData__InstanceData.cpp
//
// 0x802096F8 (52B) InteractorModule::InteractorInputManager::InstanceData::InstanceData(void)

namespace InteractorModule {

struct InteractorInputManager {
    struct InstanceData {
        int field_00;
        int field_04;
        int field_08;
        int field_0C;
        char field_10;
        char pad[3];
        int field_14;
        int field_18;
        int field_1C;

        InstanceData();
    };
};

InteractorModule::InteractorInputManager::InstanceData::InstanceData() {
    field_00 = 0;
    field_04 = 0;
    field_08 = 0;
    field_0C = 0;
    field_10 = 0;
    field_14 = -1;
    field_18 = 0;
    field_1C = 0;
}

} // namespace InteractorModule
