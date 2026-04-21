// WIP PARTIAL-FAKE / WALL (moved from src/matched/ by S13 pre-session triage, 2026-04-21)
// Diagnostic: MISMATCH 76B: interactormodule wall. Parked S12.
// Original path: src/matched/interactormodule/match_0x80213700_InteractorModule__IsCameraDirectorInControl.cpp
//
// 0x80213700 InteractorModule::IsCameraDirectorInControl (76B)

struct CameraController {
    int m_state;  // offset 0x160 from base? No, the lwz is at 352(r9) where r9 is the controller pointer
};

struct InteractorModule {
    bool IsCameraDirectorInControl(int idx);
};

extern CameraController* g_cameraControllers[64];

bool InteractorModule::IsCameraDirectorInControl(int idx) {
    CameraController* ctrl = g_cameraControllers[idx];
    if (!ctrl) return false;
    int state = ctrl->m_state;
    if (state == 0) return true;
    if (state == 8) return true;
    return false;
}
