/* __builtin_new at 0x8024A7B0 (52B) */

extern char g_err_new[16];
extern void new_handler(int, int, char *, ...);

void __builtin_new(void) {
    new_handler(0, 0, g_err_new);
}
