// 0x801D1ED0 (48b)
extern void someFunc(void*, void*);
void wrapper(char* self) {
    void* p = *(void**)(self + 4);
    if (p) someFunc(p, self);
}
