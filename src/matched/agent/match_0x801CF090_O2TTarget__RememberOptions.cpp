// 0x801CF090 (92B) O2TTarget::RememberOptions(void)
// Combined Remember — copies 6 audio bytes + 4 game ints from opts struct to SDA globals.

struct OptsBlock {
    int f_00;
    int f_04;
    char pad_08[0x18 - 0x08];
    int f_18;
    char pad_1C[0x1C - 0x1C];
    unsigned char f_1C;
    unsigned char f_1D;
    char pad_1E[0x1F - 0x1E];
    unsigned char f_1F;
    unsigned char f_20;
    char pad_21[0x24 - 0x21];
    int f_24;
    char pad_28[0x28 - 0x28];
    unsigned char f_28;
    unsigned char f_29;
};

extern char g_soundOpts[16];
extern unsigned char g_audioFlag1;
extern unsigned char g_audioFlag2;
extern unsigned char g_audioFlag3;
extern unsigned char g_audioFlag4;
extern unsigned char g_audioFlag5;
extern unsigned char g_audioFlag6;
extern int g_gameFlag1;
extern int g_gameFlag2;
extern int g_gameFlag3;
extern int g_gameFlag4;

class O2TTarget {
public:
    void RememberOptions(void);
};

void O2TTarget::RememberOptions(void) {
    OptsBlock* opts = *(OptsBlock**)g_soundOpts;
    g_audioFlag3 = opts->f_29;
    g_audioFlag4 = opts->f_28;
    g_audioFlag1 = opts->f_1C;
    g_audioFlag2 = opts->f_1D;
    g_audioFlag5 = opts->f_1F;
    g_audioFlag6 = opts->f_20;
    g_gameFlag1 = opts->f_04;
    g_gameFlag4 = opts->f_00;
    g_gameFlag2 = opts->f_18;
    g_gameFlag3 = opts->f_24;
}
