/* __tcf_11 at 0x802D0560 (44B) — auto-matched [load_addr_param_44B] */

// FLAGS: -fno-elide-constructors
extern int g_obj_802D0560[];
extern int func_802D0560(int, int);

int fwd_802D0560(void *self) {
    return func_802D0560((int)g_obj_802D0560, 2);
}
