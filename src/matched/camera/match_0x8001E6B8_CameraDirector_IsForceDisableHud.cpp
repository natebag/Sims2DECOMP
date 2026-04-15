// 0x8001E6B8 CameraDirector::IsForceDisableHud (36B)

extern int g_disableHudArr[16];

struct CameraDirector {
    char pad[364];
    int m_flags;
    int IsForceDisableHud();
};

int CameraDirector::IsForceDisableHud() {
    int result = 0;
    if (m_flags == 1) {
        result = (g_disableHudArr[0] == 0);
    }
    return result;
}
