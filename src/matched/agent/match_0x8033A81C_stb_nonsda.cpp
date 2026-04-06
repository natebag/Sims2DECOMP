// 0x8033A81C (56b)
extern int g_obj[4];
extern void func(int*, char*);
void wrapper(void* self, int param) {
    char local[8];
    local[0] = 35;
    *(int*)(local + 4) = param;
    func(g_obj, local);
}
