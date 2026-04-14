/* M2MTarget::PrepareLoadGame(void) at 0x801C2E78 (124B) */

struct Globals {
    char pad_000[0x448];
    int m_field448;
    int m_field44C;
};

extern Globals _globals;
extern void* g_nghResFile;

struct NghResFile {
    void FlushAllData();
};

struct M2MTarget {
    char pad_000[0x11C];
    int m_field11C;
    char pad_120[0x168 - 0x120];
    int m_field168;
    char pad_16C[0x180 - 0x16C];
    int m_field180;

    void PrepareLoadGame();
    int DoesMemoryDeviceExist();
    void HideWidget();
};

void M2MTarget::PrepareLoadGame() {
    m_field180 = 1;
    ((NghResFile*)g_nghResFile)->FlushAllData();
    _globals.m_field448 = 0;
    _globals.m_field44C = 0;
    if (DoesMemoryDeviceExist()) {
        m_field168 = 1;
        m_field11C = 9;
    } else {
        m_field11C = 8;
        HideWidget();
    }
}
