// 0x8017D2B0 UIReflow::SetFocus(UIScreenID) (112B)
// Pattern: state-guard + screen name lookup + vararg apt call
struct UIScreenManager {
    int GetScreenFlashName(char* buf, int id);
};
struct AptViewer {
    void NewCallFunction(char* a, char* b, char* c, int d, ...);
};

extern UIScreenManager* g_screen_mgr_sf[3];  // non-SDA
extern AptViewer* g_apt_viewer_sf;            // SDA
extern char gStr_SetFocus1[];
extern char gStr_SetFocus2[];

struct UIReflow {
    char pad[4];
    int m_state;
    void SetFocus(int id);
};

void UIReflow::SetFocus(int id) {
    if (m_state != 0) return;
    char buf[128];
    if (g_screen_mgr_sf[0]->GetScreenFlashName(buf, id)) {
        g_apt_viewer_sf->NewCallFunction(gStr_SetFocus1, 0, 0, 2, gStr_SetFocus2, buf);
    }
}
