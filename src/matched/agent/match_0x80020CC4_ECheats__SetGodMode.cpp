/* ECheats::SetGodMode(bool) at 0x80020CC4 (68B) */

struct ECheatsData {
    char pad[0x3BC];
    int m_3BC;
    int m_3C0;
    int pad2;
    int m_3C8;
    int m_3CC;
    int m_3D0;
    int pad3;
    int m_3D8;
    int m_3DC;
    char pad4[0x3F0 - 0x3E0];
    int m_3F0;
};

extern ECheatsData g_echeats;

struct GodModeData {
    char pad[0x61C8];
    int m_godMode;
};

extern GodModeData g_godModeBase;

struct ECheats {
    void SetGodMode(int godMode);
};

void ECheats::SetGodMode(int godMode) {
    if (godMode) {
        g_echeats.m_3D0 = 1;
        g_echeats.m_3C0 = 1;
        g_echeats.m_3C8 = 1;
        g_echeats.m_3CC = 1;
        g_echeats.m_3BC = 1;
        g_echeats.m_3F0 = 1;
        g_echeats.m_3DC = 1;
        g_echeats.m_3D8 = 1;
    } else {
        g_godModeBase.m_godMode = godMode;
    }
}
