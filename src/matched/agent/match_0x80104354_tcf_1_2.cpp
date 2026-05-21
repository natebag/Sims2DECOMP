// 0x80104354 __tcf_1_2() (80B) — vector<int> static dtor

extern "C" void __builtin_delete_1(void* p);
extern "C" void __nd_M_dealloc(void* p, unsigned int sz);

extern char g_vec_80486370[16];

extern "C" void __tcf_1_2() {
    char* p = *(char**)g_vec_80486370;
    char* base = g_vec_80486370;
    if (p == 0) return;
    char* end = *(char**)(base + 12);
    unsigned int sz = (unsigned int)(end - p) & ~3u;
    if (sz > 0x80) {
        __builtin_delete_1(p);
        return;
    }
    __nd_M_dealloc(p, sz);
}
