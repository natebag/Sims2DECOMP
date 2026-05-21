// 0x800ABC90 __tcf_0() (80B)

extern "C" void __builtin_delete_1(void* p);
extern "C" void __nd_M_dealloc(void* p, unsigned int sz);

extern char g_vec_80485DB0[16];

extern "C" void __tcf_0() {
    char* p = *(char**)g_vec_80485DB0;
    char* base = g_vec_80485DB0;
    if (p == 0) return;
    char* end = *(char**)(base + 12);
    unsigned int sz = (unsigned int)(end - p) & ~1u;
    if (sz > 0x80) {
        __builtin_delete_1(p);
        return;
    }
    __nd_M_dealloc(p, sz);
}
