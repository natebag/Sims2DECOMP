// 0x8033A4F8 (56b)
extern int g_obj[4];
extern void func(int*, char*);
void wrapper(void* self, int param) {
    char local[8];
    local[0] = 20;
    *(int*)(local + 4) = param;
    func(g_obj, local);
}
