/* 0x800663e8 (84 bytes) - SAnimator2::triggerCameraBlur(char *) */
class SAnimator2 {
public:
    void triggerCameraBlur(char* name);
    void DoTriggerCameraBlur(void* ctrl);
};

extern void* g_sdaBlurObj;

void SAnimator2::triggerCameraBlur(char* name) {
    void* sdaObj = g_sdaBlurObj;
    void* vtable = *(void**)sdaObj;
    short offset = *(short*)((char*)vtable + 392);
    void* func = *(void**)((char*)vtable + 396);
    char* controller = (char*)sdaObj + offset;
    void* result = ((void* (*)(char*))func)(controller);
    if (result == 0) goto skip;
    DoTriggerCameraBlur(result);
skip:
    return;
}
