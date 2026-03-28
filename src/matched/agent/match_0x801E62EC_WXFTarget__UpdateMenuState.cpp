/* WXFTarget::UpdateMenuState(char *, char *) at 0x801E62EC (132b) */

extern int AtoI(const char *str);

struct WXFTarget {
    char pad_00[0x8C];
    int m_menuState;
    int m_prevMenuState;

    void UpdateMenuState(char *a, char *b);
    void UpdateText();
    void UpdateShaders();
};

void WXFTarget::UpdateMenuState(char *a, char *b) {
    int val = AtoI(b);
    switch (val) {
    case 0:
        m_prevMenuState = m_menuState;
        m_menuState = val;
        UpdateText();
        break;
    case 1:
        m_prevMenuState = m_menuState;
        m_menuState = val;
        break;
    case 2:
        m_prevMenuState = m_menuState;
        m_menuState = val;
        break;
    }
    UpdateShaders();
}
