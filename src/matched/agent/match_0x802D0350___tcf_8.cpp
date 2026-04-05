/* __tcf_8 at 0x802D0350 (44B) — auto-matched [load_addr_param_44B] */

// FLAGS: -fno-elide-constructors
extern int g_obj_802D0350[];
extern int func_802D0350(int, int);

int fwd_802D0350(void *self) {
    return func_802D0350((int)g_obj_802D0350, 2);
}
