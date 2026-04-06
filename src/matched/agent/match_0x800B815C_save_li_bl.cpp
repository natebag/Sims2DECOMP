// 0x800B815C (56b)
extern void someFunc(void*, int, int);
void* wrapper(void* self) {
    someFunc(self, 0, 68);
    return self;
}
