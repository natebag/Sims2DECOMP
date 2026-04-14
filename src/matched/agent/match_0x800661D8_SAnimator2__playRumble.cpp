typedef unsigned char u8;

extern u8* g_playRumbleGlobal;
extern void playRumbleDataElement(u8* self, void* elem);

void SAnimator2_playRumble(u8* self, char* /*name*/) {
    u8* global = g_playRumbleGlobal;
    u8* dispatch = *(u8**)global;
    short offset = *(short*)(dispatch + 0x178);
    int func = *(int*)(dispatch + 0x17C);
    u8* obj = global + offset;
    void* result = ((void* (*)(u8*))func)(obj);
    if (result != 0) {
        playRumbleDataElement(self, result);
    }
}
