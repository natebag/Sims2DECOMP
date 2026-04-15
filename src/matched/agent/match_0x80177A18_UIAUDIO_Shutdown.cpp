// 0x80177A18 (72B) UIAUDIO::Shutdown(void)

struct UIAUDIO_Base { char pad[116]; };

struct UIAUDIO_Impl : public UIAUDIO_Base {
    virtual void Destroy(int mode) = 0;
};

extern UIAUDIO_Impl* g_UIAUDIO_instance;

struct UIAUDIO {
    static void Shutdown();
};

void UIAUDIO::Shutdown() {
    if (g_UIAUDIO_instance) {
        g_UIAUDIO_instance->Destroy(3);
        g_UIAUDIO_instance = 0;
    }
}
