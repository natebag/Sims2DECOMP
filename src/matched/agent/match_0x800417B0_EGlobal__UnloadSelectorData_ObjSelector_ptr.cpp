/* EGlobal__UnloadSelectorData_ObjSelector_ptr at 0x800417B0 (44B) — auto-matched [load_addr_param_44B] */

// FLAGS: -fno-elide-constructors
extern int g_obj_800417B0[];
extern int func_800417B0(int, int, int);

int fwd_800417B0(void *self, int a0) {
    return func_800417B0((int)g_obj_800417B0, a0, 1);
}
