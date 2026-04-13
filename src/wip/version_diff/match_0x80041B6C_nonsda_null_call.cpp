// 0x80041B6C (48b)
// FLAGS: -fno-schedule-insns
extern int g_var[4];
extern void someFunc(void);
void wrapper() {
    if (g_var[0]) someFunc();
}
