typedef unsigned char u8;

extern u8* g_someGlobal;
extern void triggerCameraBloomDataElement(u8* self, void* elem);

void SAnimator2_triggerCameraBloom(u8* self, char* /*name*/) {
    u8* global = g_someGlobal;
    u8* dispatch = *(u8**)global;
    short offset = *(short*)(dispatch + 0x180);
    int func = *(int*)(dispatch + 0x184);
    u8* obj = global + offset;
    void* result = ((void* (*)(u8*))func)(obj);
    if (result != 0) {
        triggerCameraBloomDataElement(self, result);
    }
}
