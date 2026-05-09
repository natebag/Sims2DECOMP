// PRAGMA_STUB: HUDTarget::GotoMainMenu(void)
// 0x801899E8 HUDTarget::GotoMainMenu(void) (48B)
struct HUDTarget {
    char pad[256];
    char m_gotoFlag;
};

extern char g_mainMenuName[64];  // non-SDA
extern void H2DTarget__LoadScreen(char* name);

void HUDTarget__GotoMainMenu(HUDTarget* self) {
    self->m_gotoFlag = 1;
    H2DTarget__LoadScreen(g_mainMenuName);
}
