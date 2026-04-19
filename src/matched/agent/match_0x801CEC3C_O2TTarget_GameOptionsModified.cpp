// 0x801CEC3C (84B) O2TTarget::GameOptionsModified(void)
// Sibling to AudioOptionsModified — compare 4 int fields instead of bytes.

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
    int GameOptionsModified(void);
};

int O2TTarget::GameOptionsModified(void) {
    GameOpts* opts = *(GameOpts**)g_gameOpts;
    if (opts->f_04 == g_gameFlag1
     && opts->f_18 == g_gameFlag2
     && opts->f_24 == g_gameFlag3
     && opts->f_00 == g_gameFlag4) {
        return 0;
    }
    return 1;
}
