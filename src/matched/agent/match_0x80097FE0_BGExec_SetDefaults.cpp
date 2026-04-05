// BGExec_SetDefaults(void)
// Address: 0x80097FE0 | Size: 48 bytes
// FLAGS: -fno-elide-constructors

struct BGExec;
extern BGExec g_bgExec;  // SDA global at 0x80475DCC

extern void BGExec_SetDefaults_impl(BGExec* exec);

extern int g_bgDefaultsSet;  // SDA global at 0x8047AC18

void BGExec_SetDefaults() {
    BGExec_SetDefaults_impl(&g_bgExec);
    g_bgDefaultsSet = 1;
}
