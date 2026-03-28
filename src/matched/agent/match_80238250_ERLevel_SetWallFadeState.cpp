// 0x80238250 (12 bytes) - ERLevel::SetWallFadeState(EWallUpDownStateType)
// addis r3, r3, 3; stw r4, -7468(r3); blr  =>  m_wallFadeState = val; (offset 0x2E2D4)

class ERLevel;

struct ERLevel_SWFS {
    char pad[0x2E2D4];
    int m_wallFadeState;
    void SetWallFadeState(int val);
};
void ERLevel_SWFS::SetWallFadeState(int val) {
    m_wallFadeState = val;
}
