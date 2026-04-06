// 0x802C982C (48b)
extern void func1(void*, int, void*);
extern void func2(void*);
void wrapper(void* self) {
    char local[16];
    func1(self, 2, local);
    func2(local);
}
