// 0x801220D0 __tcf_1_4() (80B) — vector<int> variant 2

extern "C" void __builtin_delete_1(void* p);
extern "C" void __nd_M_dealloc(void* p, unsigned int sz);

extern char g_vec_804866AC[16];

extern "C" void __tcf_1_4() {
    char* p = *(char**)g_vec_804866AC;
    char* base = g_vec_804866AC;
    if (p == 0) return;
    char* end = *(char**)(base + 12);
    unsigned int sz = (unsigned int)(end - p) & ~3u;
    if (sz > 0x80) {
        __builtin_delete_1(p);
        return;
    }
    __nd_M_dealloc(p, sz);
}
