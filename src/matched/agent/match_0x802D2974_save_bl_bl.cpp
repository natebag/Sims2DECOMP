// 0x802D2974 (56b)
extern void* func1(void*);
extern void func2(void*, void*, int);
void wrapper(void* a, void* b) {
    void* r = func1(a);
    func2(r, b, 0);
}
