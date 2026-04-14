// 0x8008CC90 (48b)
extern int g_var[4];
extern void someFunc(int);
void wrapper() {
    g_var[0] = 0;
    someFunc(4);
}
