// 0x80014F78 (56b)
extern int g_var[4];
extern char g_flag[4];
extern void someFunc(void);
void wrapper() {
    if (g_var[0]) someFunc();
    *(int*)g_flag = 1;
}
