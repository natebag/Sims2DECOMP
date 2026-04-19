/* InteractorModule::WallManipulator::GetAffectedWallHeight(void) at 0x80224048 (24B) */

extern float g_wallHeightHigh;
extern float g_wallHeightLow;

struct WallManipulator_GAWH {
    char pad[0xC4];
    unsigned int m_flags;
    float GetAffectedWallHeight();
};

float WallManipulator_GAWH::GetAffectedWallHeight() {
    if (m_flags & 0x100) return g_wallHeightHigh;
    return g_wallHeightLow;
}
