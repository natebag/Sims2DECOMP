/* __builtin_delete at 0x8024A818 (52B) */

extern char g_err___builtin_delete[16];
extern void __builtin_delete_handler(int, int, char *, ...);

void __builtin_delete(void) {
    __builtin_delete_handler(0, 0, g_err___builtin_delete);
}
