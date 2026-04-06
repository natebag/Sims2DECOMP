// 0x801D1F00 (48b)
extern void someFunc(void*, void*);
void wrapper(char* self) {
    void* p = *(void**)(self + 4);
    if (p) someFunc(p, self);
}
