extern int g_menuState;
extern int g_menuActive;
extern int g_menuProgress;
int ObjTestSim_IsMenuInProgress() {
    int r = 0;
    if (g_menuState) {
        if (g_menuActive) {
            if (g_menuProgress) r = 1;
        }
    }
    return r;
}
