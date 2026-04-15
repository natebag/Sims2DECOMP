/* 0x800661d8 (84 bytes) - SAnimator2::playRumble(char *) */
class SAnimator2 {
public:
    void playRumble(char* name);
    void DoPlayRumble(void* ctrl);
};

extern void* g_sdaRumbleObj;

void SAnimator2::playRumble(char* name) {
    void* sdaObj = g_sdaRumbleObj;
    void* vtable = *(void**)sdaObj;
    short offset = *(short*)((char*)vtable + 376);
    void* func = *(void**)((char*)vtable + 380);
    char* controller = (char*)sdaObj + offset;
    void* result = ((void* (*)(char*))func)(controller);
    if (result == 0) goto skip;
    DoPlayRumble(result);
skip:
    return;
}
