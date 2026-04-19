// 0x801CF054 (60B) O2TTarget::RestoreGameOptions(void)
// Inverse of GameOptionsModified — write SDA flags into 4 int fields of
// GameOpts struct pointed to by g_gameOpts. Pointer reload per write
// (compiler aliasing).

struct GameOpts {
    int f_00;
    int f_04;
    char pad_08[0x18 - 0x08];
    int f_18;
    char pad_1C[0x24 - 0x1C];
    int f_24;
};

struct OptsBase {
    char pad_000[0x148];
    GameOpts* gameOpts;
};
extern OptsBase g_optsBase;

extern int g_gameFlag1;
extern int g_gameFlag2;
extern int g_gameFlag3;
extern int g_gameFlag4;

class O2TTarget {
public:
    void RestoreGameOptions(void);
};

void O2TTarget::RestoreGameOptions(void) {
    g_optsBase.gameOpts->f_04 = g_gameFlag1;
    g_optsBase.gameOpts->f_18 = g_gameFlag2;
    g_optsBase.gameOpts->f_24 = g_gameFlag3;
    g_optsBase.gameOpts->f_00 = g_gameFlag4;
}
