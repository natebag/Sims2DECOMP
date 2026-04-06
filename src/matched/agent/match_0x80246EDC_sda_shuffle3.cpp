// 0x80246EDC (48b)
extern void* g_sda;
extern void func(void*, void*, void*);
void wrapper(void* a, void* b) {
    func(g_sda, a, b);
}
