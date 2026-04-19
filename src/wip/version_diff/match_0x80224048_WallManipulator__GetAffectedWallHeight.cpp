// 0x80224048 (24B) InteractorModule::WallManipulator::GetAffectedWallHeight(void)
// STATUS: mismatch (S11 Audit #4) — permuter candidate
// 24B MISMATCH vs DOL. Small function, likely instruction-scheduling or register-allocation
// drift. Good target for HaikuPermuter when token budget allows.

extern float g_wallH_high;
extern float g_wallH_low;

struct IM_WM_GAH {
    char pad[0xC4];
    unsigned int m_C4;
    float GetAffectedWallHeight();
};

float IM_WM_GAH::GetAffectedWallHeight() {
    if (m_C4 & 0x100) return g_wallH_high;
    return g_wallH_low;
}
