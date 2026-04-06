// 0x802C6A6C (56b)
extern void someFunc(void*, int, int);
void* wrapper(void* self) {
    someFunc(self, 0, 4);
    return self;
}
