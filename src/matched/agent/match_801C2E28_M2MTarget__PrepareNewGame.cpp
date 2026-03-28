/* M2MTarget::PrepareNewGame(void) at 0x801C2E28 (80B) */

struct UIDB {
    static void UIDBSetInt(char*, int);
};

extern char s_newGameStr[];

struct M2MTarget {
    char pad_000[0x11C];
    int m_field11C;
    char pad_120[0x168 - 0x120];
    int m_field168;
    char pad_16C[0x180 - 0x16C];
    int m_field180;

    void PrepareNewGame();
};

void M2MTarget::PrepareNewGame() {
    m_field180 = 1;
    m_field11C = 5;
    UIDB::UIDBSetInt(s_newGameStr, 7);
    m_field168 = 3;
}
