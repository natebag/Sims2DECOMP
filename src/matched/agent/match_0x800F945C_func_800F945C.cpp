/* auto at 0x800F945C (36B) [sda_load_call] */

extern char g_800F945C[4];
extern int wrap_800F945C(int);
int func_800F945C(void) { return wrap_800F945C(*(int*)g_800F945C); }
