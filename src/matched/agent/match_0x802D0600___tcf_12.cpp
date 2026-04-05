/* __tcf_12 at 0x802D0600 (44B) — auto-matched [load_addr_param_44B] */

// FLAGS: -fno-elide-constructors
extern int g_obj_802D0600[];
extern int func_802D0600(int, int);

int fwd_802D0600(void *self) {
    return func_802D0600((int)g_obj_802D0600, 2);
}
