// 0x801779dc (44B) UIAUDIO::Instance(void)

struct UIAUDIO {
    char data[120];
    UIAUDIO();
    static UIAUDIO* Instance();
};

extern UIAUDIO* g_UIAUDIO_instance;

UIAUDIO* UIAUDIO::Instance() {
    if (!g_UIAUDIO_instance) {
        g_UIAUDIO_instance = new UIAUDIO();
    }
    return g_UIAUDIO_instance;
}
