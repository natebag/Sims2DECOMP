/* 0x8006634c (84 bytes) - SAnimator2::triggerCameraBloom(char *) */
class SAnimator2 {
public:
    void triggerCameraBloom(char* name);
    void DoTriggerCameraBloom(void* ctrl);
};

extern void* g_sdaBloomObj;

void SAnimator2::triggerCameraBloom(char* name) {
    void* sdaObj = g_sdaBloomObj;
    void* vtable = *(void**)sdaObj;
    short offset = *(short*)((char*)vtable + 384);
    void* func = *(void**)((char*)vtable + 388);
    char* controller = (char*)sdaObj + offset;
    void* result = ((void* (*)(char*))func)(controller);
    if (result == 0) goto skip;
    DoTriggerCameraBloom(result);
skip:
    return;
}
