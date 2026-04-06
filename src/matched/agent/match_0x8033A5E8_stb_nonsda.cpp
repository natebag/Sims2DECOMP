// 0x8033A5E8 (56b)
extern int g_obj[4];
extern void func(int*, char*);
void wrapper(void* self, int param) {
    char local[8];
    local[0] = 9;
    *(int*)(local + 4) = param;
    func(g_obj, local);
}
