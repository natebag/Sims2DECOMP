// 0x8003F9FC (24B) EGlobal::GetWin(void)

struct EGlobal_GW {
    char pad[208];
    char* m_win;
    char* GetWin();
};

char* EGlobal_GW::GetWin() {
    if (!m_win) return 0;
    return m_win + 16;
}
