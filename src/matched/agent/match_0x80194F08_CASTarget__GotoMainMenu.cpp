/* CASTarget::GotoMainMenu(void) at 0x80194F08 (132b) */

extern void GotoScreen(char*);
extern int GetScreenType(char*);

extern char g_screenName[];
extern char g_menuA[];
extern char g_menuB[];
extern char g_menuC[];

struct CASTarget {
    char pad[0x104];
    int m_mode;

    void GotoMainMenu();
    int UnloadLastScreen();
};

void CASTarget::GotoMainMenu() {
    UnloadLastScreen();
    if (m_mode == 3) {
        GotoScreen(g_menuA);
    } else {
        switch (GetScreenType(g_screenName)) {
        case 0:
            GotoScreen(g_menuB);
            break;
        case 1:
            GotoScreen(g_menuC);
            break;
        }
    }
}
