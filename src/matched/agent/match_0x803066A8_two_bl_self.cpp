// 0x803066A8 (56b)
extern void func1(void*);
extern void func2(void*);
void wrapper(char* self) {
    func1(self + 4);
    func2(self + 28);
}
