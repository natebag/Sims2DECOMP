// WIP PARTIAL-FAKE / WALL (moved from src/matched/ by S13 pre-session triage, 2026-04-21)
// Diagnostic: MISMATCH 44B: ESimsCam init wall. Parked S12.
// Original path: src/matched/esimscam/match_0x80016A8C_ESimsCam__Init.cpp
//
// 0x80016A8C ESimsCam::Init (44B)
// FLAGS: -fno-schedule-insns -fno-schedule-insns2

extern int g_simsCamInitValue;

struct ESimsCam {
    char pad[972];
    int field3CC;       // 972
    int field3D0;       // 976
    int field3D4;       // 980
    char pad2[160];     // 984-1143
    int field478;       // 1144
    char pad3[208];     // 1148-1355
    int field54C;       // 1356
    char pad4[4];       // 1360-1363
    int field554;       // 1364
    int field558;       // 1368
    int field55C;       // 1372
};

void ESimsCam_Init(ESimsCam* this_) {
    int g = g_simsCamInitValue;
    int z = 0;
    this_->field55C = z;
    this_->field3D0 = g;
    this_->field54C = z;
    this_->field3D4 = z;
    this_->field478 = z;
    this_->field554 = z;
    this_->field558 = z;
    this_->field3CC = g;
}
