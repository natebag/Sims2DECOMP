// 0x80187EB4 (112B) HUDTarget::HideHUD(void)
// Triple-guard then varargs apt call. Signature sibling to UIReflow::SetFocus.

struct AptViewer {
    void NewCallFunction(char*, char*, char*, int, ...);
};

extern AptViewer* g_aptViewer_hh;   // SDA -25136(r13)
extern char gStr_hideHUD[];          // non-SDA

extern int GetTutorialLocks(int);

class HUDTarget {
public:
    char pad_000[0xE4];
    int m_field_0E4;
    unsigned char m_field_0E8;
    char pad_0E9[3];
    int m_field_0EC;

    void HideHUD(void);
};

void HUDTarget::HideHUD(void) {
    if (GetTutorialLocks(m_field_0EC) & 1) return;
    if (m_field_0E4 == 0) return;
    if (m_field_0E8 != 2) return;
    g_aptViewer_hh->NewCallFunction(gStr_hideHUD, 0, 0, 0);
}
