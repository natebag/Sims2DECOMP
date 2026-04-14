/* __builtin_vec_new at 0x8024A7E4 (52B) */

extern char g_err___builtin_vec_new[16];
extern void __builtin_vec_new_handler(int, int, char *, ...);

void __builtin_vec_new(void) {
    __builtin_vec_new_handler(0, 0, g_err___builtin_vec_new);
}
