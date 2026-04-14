typedef unsigned char u8;

extern u8* g_someGlobal;
extern void triggerCameraBlurDataElement(u8* self, void* elem);

void SAnimator2_triggerCameraBlur(u8* self, char* /*name*/) {
    u8* global = g_someGlobal;
    u8* dispatch = *(u8**)global;
    short offset = *(short*)(dispatch + 0x188);
    int func = *(int*)(dispatch + 0x18C);
    u8* obj = global + offset;
    void* result = ((void* (*)(u8*))func)(obj);
    if (result != 0) {
        triggerCameraBlurDataElement(self, result);
    }
}
