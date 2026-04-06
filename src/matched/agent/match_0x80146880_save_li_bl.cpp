// 0x80146880 (56b)
extern void someFunc(void*, int, int);
void* wrapper(void* self) {
    someFunc(self, 0, 56);
    return self;
}
