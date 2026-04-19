// 0x80187E3C (120B) HUDTarget::ShowHUD(void)
// Sibling to HideHUD, with UpdateClock call before the third guard.

struct AptViewer {
    void NewCallFunction(char*, char*, char*, int, ...);
};

extern AptViewer* g_aptViewer_sh;   // SDA -25136(r13)
extern char gStr_showHUD[];          // non-SDA

extern int GetTutorialLocks(int);

class HUDTarget {
public:
    char pad_000[0xE4];
    int m_field_0E4;
    unsigned char m_field_0E8;
    char pad_0E9[3];
    int m_field_0EC;

    void UpdateClock(void);
    void ShowHUD(void);
};

void HUDTarget::ShowHUD(void) {
    if (GetTutorialLocks(m_field_0EC) & 1) return;
    if (m_field_0E4 == 0) return;
    this->UpdateClock();
    if (m_field_0E8 != 0) return;
    g_aptViewer_sh->NewCallFunction(gStr_showHUD, 0, 0, 0);
}
