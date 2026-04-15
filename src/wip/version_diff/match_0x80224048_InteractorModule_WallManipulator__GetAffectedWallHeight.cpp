// 0x80224048 InteractorModule::WallManipulator::GetAffectedWallHeight(void) (24B)

extern float g_wallHeight1; // SDA at r13-21092
extern float g_wallHeight2; // SDA at r13-21096

struct WallManipulator {
    char pad[0xC4];
    int m_flags;
    float GetAffectedWallHeight(void);
};

float WallManipulator::GetAffectedWallHeight(void) {
    if (m_flags & 0x100) return g_wallHeight1;
    return g_wallHeight2;
}
