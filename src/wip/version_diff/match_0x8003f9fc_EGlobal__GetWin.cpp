// 0x8003f9fc EGlobal::GetWin(void) (24B)

struct EGlobal {
    char pad[0xD0];
    void* m_win;
    void* GetWin(void);
};

void* EGlobal::GetWin(void) {
    void* win = m_win;
    if (win) return (char*)win + 0x10;
    return 0;
}
