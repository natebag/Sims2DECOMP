/* __tcf_0_13 at 0x802CFE38 (44B) — auto-matched [load_addr_param_44B] */

// FLAGS: -fno-elide-constructors
extern int g_obj_802CFE38[];
extern int func_802CFE38(int, int);

int fwd_802CFE38(void *self) {
    return func_802CFE38((int)g_obj_802CFE38, 2);
}
