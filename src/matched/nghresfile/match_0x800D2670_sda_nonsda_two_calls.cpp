// 0x800D2670 (48b)
extern void* g_sda;
extern int g_str[4];
extern void* func1(void*);
extern void func2(void*, int*);
void wrapper() {
    void* r = func1(g_sda);
    func2(r, g_str);
}
