/* __builtin_vec_delete at 0x8024A84C (52B) */

extern char g_err___builtin_vec_delete[16];
extern void __builtin_vec_delete_handler(int, int, char *, ...);

void __builtin_vec_delete(void) {
    __builtin_vec_delete_handler(0, 0, g_err___builtin_vec_delete);
}
