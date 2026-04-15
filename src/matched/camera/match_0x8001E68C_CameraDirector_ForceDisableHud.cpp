// 0x8001E68C CameraDirector::ForceDisableHud(bool) (44B)

extern int g_disableHudArr[16];

struct CameraDirector {
    char pad[364];
    int m_disableHud;
    void ForceDisableHud(bool disable);
};

void CameraDirector::ForceDisableHud(bool disable) {
    if (disable == 1 && g_disableHudArr[0] == 0) {
        m_disableHud = disable;
    } else {
        m_disableHud = 0;
    }
}
