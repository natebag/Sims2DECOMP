// 0x801BC938 INGTarget::play_error_sound() (76B)

extern "C" void* __builtin_new_1(unsigned int);

class UIAUDIO {
public:
    UIAUDIO();
    void PlaySound(unsigned int id);
};

extern "C" UIAUDIO* __ct__7UIAUDIOFv(void* p);

extern UIAUDIO* g_UIAUDIO_SDA;

class INGTarget {
public:
    int play_error_sound();
};

int INGTarget::play_error_sound() {
    if (g_UIAUDIO_SDA == 0) {
        g_UIAUDIO_SDA = __ct__7UIAUDIOFv(__builtin_new_1(120));
    }
    g_UIAUDIO_SDA->PlaySound(0x3804219FU);
    return 1;
}
