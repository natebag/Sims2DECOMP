// FLAGS: -fno-elide-constructors
// 0x801F0868 (84 bytes)
// INVTarget::PopCurrentFilter(void)

extern "C" void* funcA(void* mgr, int val);
extern "C" void* funcB(void* mgr, void* prev);
extern "C" void funcC(void* obj, int val);
extern void* g_mgr; // SDA global (4 bytes, <=8 → r13-relative)

void INVTarget_PopCurrentFilter(char* self) {
    void* mgr = g_mgr;
    void* a = funcA(mgr, *(int*)(self + 0x84));
    void* b = funcB(mgr, a);
    funcC(b, *(int*)(self + 0xD0));
    *(int*)(self + 0xD0) = 0;
}
