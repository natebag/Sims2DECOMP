// 0x802DF6BC (56b)
extern void* func1(void*);
extern void func2(void*, void*, int);
void wrapper(void* a, void* b) {
    void* r = func1(a);
    func2(r, b, 0);
}
