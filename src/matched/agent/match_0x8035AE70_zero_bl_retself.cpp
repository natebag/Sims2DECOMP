// 0x8035AE70 (56b)
extern void func(void*);
void* wrapper(char* self) {
    *(int*)self = 0;
    func(self);
    return self;
}
