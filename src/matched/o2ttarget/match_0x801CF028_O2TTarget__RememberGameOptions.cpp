// 0x801CF028 (44B) O2TTarget::RememberGameOptions(void)
// Inverse of GameOptionsModified — copy 4 int fields to SDA globals.

struct GameOpts {
    int f_00;
    int f_04;
    char pad_08[0x18 - 0x08];
    int f_18;
    char pad_1C[0x24 - 0x1C];
    int f_24;
};

extern char g_gameOpts[16];
extern int g_gameFlag1;
extern int g_gameFlag2;
extern int g_gameFlag3;
extern int g_gameFlag4;

class O2TTarget {
public:
    void RememberGameOptions(void);
};

void O2TTarget::RememberGameOptions(void) {
    GameOpts* opts = *(GameOpts**)g_gameOpts;
    g_gameFlag1 = opts->f_04;
    g_gameFlag4 = opts->f_00;
    g_gameFlag2 = opts->f_18;
    g_gameFlag3 = opts->f_24;
}
