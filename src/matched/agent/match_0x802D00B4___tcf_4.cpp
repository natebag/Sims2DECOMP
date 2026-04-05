/* __tcf_4 at 0x802D00B4 (44B) — auto-matched [load_addr_param_44B] */

// FLAGS: -fno-elide-constructors
extern int g_obj_802D00B4[];
extern int func_802D00B4(int, int);

int fwd_802D00B4(void *self) {
    return func_802D00B4((int)g_obj_802D00B4, 2);
}
