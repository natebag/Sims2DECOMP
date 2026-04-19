// 0x801CEBE8 (84B) O2TTarget::AudioOptionsModified(void)
// Compare 4 byte fields of non-SDA struct vs 4 SDA globals; return 1 if any differ.

struct SoundOpts {
    char pad_00[0x1C];
    unsigned char f_1C;
    unsigned char f_1D;
    char pad_1E[0x28 - 0x1E];
    unsigned char f_28;
    unsigned char f_29;
};

extern char g_soundOpts[16];  // non-SDA ptr storage
extern unsigned char g_audioFlag1;
extern unsigned char g_audioFlag2;
extern unsigned char g_audioFlag3;
extern unsigned char g_audioFlag4;

class O2TTarget {
public:
    int AudioOptionsModified(void);
};

int O2TTarget::AudioOptionsModified(void) {
    SoundOpts* opts = *(SoundOpts**)g_soundOpts;
    if (opts->f_1C == g_audioFlag1
     && opts->f_1D == g_audioFlag2
     && opts->f_29 == g_audioFlag3
     && opts->f_28 == g_audioFlag4) {
        return 0;
    }
    return 1;
}
