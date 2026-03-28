/* ProfileHook(void) at 0x80005438 (16B) */

extern int g_profileCount;

void ProfileHook(void) {
    g_profileCount = g_profileCount + 1;
}
