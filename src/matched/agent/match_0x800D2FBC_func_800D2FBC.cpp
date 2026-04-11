/* auto at 0x800D2FBC (36B) [sda_extra_param_call] */

extern char g_800D2FBC[4];
extern int wrap_800D2FBC(int, int, int);
int func_800D2FBC(int a0, int a1) { return wrap_800D2FBC(a0, a1, *(int*)g_800D2FBC); }
