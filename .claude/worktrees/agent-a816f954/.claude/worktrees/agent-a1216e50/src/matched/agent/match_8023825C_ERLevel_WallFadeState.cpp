// 0x8023825C (12 bytes) - ERLevel::WallFadeState(void)
// addis r3, r3, 3; lwz r3, -7468(r3); blr  =>  return m_wallFadeState; (offset 0x2E2D4)

class ERLevel;

struct ERLevel_WFS {
    char pad[0x2E2D4];
    int m_wallFadeState;
    int WallFadeState();
};
int ERLevel_WFS::WallFadeState() {
    return m_wallFadeState;
}
