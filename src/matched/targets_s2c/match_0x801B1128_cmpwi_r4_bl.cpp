// 0x801B1128 (48b)
extern int g_str[4];
extern void someFunc(int*);
void wrapper(void* a, int b) {
    if (b == 1) someFunc(g_str);
}
