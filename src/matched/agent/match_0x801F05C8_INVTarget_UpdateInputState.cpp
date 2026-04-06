// FLAGS: -fno-elide-constructors
// 0x801F05C8 (88 bytes)
// INVTarget::UpdateInputState(void)

extern "C" void* funcA(void* mgr, int val);
extern "C" void* funcB(void* mgr, void* prev);
extern "C" void* funcC(void* obj, int val);
extern void* g_mgr; // SDA global

void INVTarget_UpdateInputState(char* self) {
    void* mgr = g_mgr;
    void* a = funcA(mgr, *(int*)(self + 0x84));
    void* b = funcB(mgr, a);
    if (b != 0) {
        *(int*)(self + 0x8C) = (int)funcC(b, *(int*)(self + 0xD0));
    }
}
