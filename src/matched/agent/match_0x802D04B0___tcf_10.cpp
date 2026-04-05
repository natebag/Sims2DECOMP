/* __tcf_10 at 0x802D04B0 (44B) — auto-matched [load_addr_param_44B] */

// FLAGS: -fno-elide-constructors
extern int g_obj_802D04B0[];
extern int func_802D04B0(int, int);

int fwd_802D04B0(void *self) {
    return func_802D04B0((int)g_obj_802D04B0, 2);
}
