// 0x802C97CC (48b)
extern void func1(void*, int, void*);
extern void func2(void*);
void wrapper(void* self) {
    char local[16];
    func1(self, 0, local);
    func2(local);
}
