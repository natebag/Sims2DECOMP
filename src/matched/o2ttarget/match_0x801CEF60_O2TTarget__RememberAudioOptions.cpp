// 0x801CEF60 (44B) O2TTarget::RememberAudioOptions(void)
// Inverse of AudioOptionsModified: copy 4 byte fields of SoundOpts into SDA globals.

struct SoundOpts {
    char pad_00[0x1C];
    unsigned char f_1C;
    unsigned char f_1D;
    char pad_1E[0x28 - 0x1E];
    unsigned char f_28;
    unsigned char f_29;
};

extern char g_soundOpts[16];
extern unsigned char g_audioFlag1;
extern unsigned char g_audioFlag2;
extern unsigned char g_audioFlag3;
extern unsigned char g_audioFlag4;

class O2TTarget {
public:
    void RememberAudioOptions(void);
};

void O2TTarget::RememberAudioOptions(void) {
    SoundOpts* opts = *(SoundOpts**)g_soundOpts;
    g_audioFlag3 = opts->f_29;
    g_audioFlag4 = opts->f_28;
    g_audioFlag1 = opts->f_1C;
    g_audioFlag2 = opts->f_1D;
}
