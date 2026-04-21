// WIP PARTIAL-FAKE / WALL (moved from src/matched/ by S13 pre-session triage, 2026-04-21)
// Diagnostic: MISMATCH 56B: PlacementObject ctor wall. Parked S12.
// Original path: src/matched/interactormodule/match_0x8021AAB8_InteractorModule__PlacementObject__PlacementObject.cpp
//
// 0x8021AAB8 InteractorModule::PlacementObject::PlacementObject (56B)
// FLAGS: -O0

struct InteractorModule_PlacementObject {
    int field00;
    int field04;
    char pad[12];
    int field14;
    int field18;
    int field1C;
    char field20;
    char pad2[3];
    int field24;
    InteractorModule_PlacementObject();
};

InteractorModule_PlacementObject::InteractorModule_PlacementObject() {
    field00 = 0;
    field04 = 0;
    field14 = 0;
    field18 = 0;
    field1C = 0;
    field20 = 0;
    field24 = 0;
}
