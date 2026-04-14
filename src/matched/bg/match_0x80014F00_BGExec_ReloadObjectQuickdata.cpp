/* BGExec_ReloadObjectQuickdata(void) at 0x80014F00 (48B) */

extern char g_simsAppBG3[];
extern int g_bgDone;

void ReloadObjectQuickdata(void*);

void BGExec_ReloadObjectQuickdata(void) {
    ReloadObjectQuickdata(g_simsAppBG3);
    g_bgDone = 1;
}
