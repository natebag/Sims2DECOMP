// 0x800ABCE0 __tcf_1() (80B) — twin of __tcf_0 at different addr

extern "C" void __builtin_delete_1(void* p);
extern "C" void __nd_M_dealloc(void* p, unsigned int sz);

extern char g_vec_80485DC0[16];

extern "C" void __tcf_1() {
    char* p = *(char**)g_vec_80485DC0;
    char* base = g_vec_80485DC0;
    if (p == 0) return;
    char* end = *(char**)(base + 12);
    unsigned int sz = (unsigned int)(end - p) & ~1u;
    if (sz > 0x80) {
        __builtin_delete_1(p);
        return;
    }
    __nd_M_dealloc(p, sz);
}
