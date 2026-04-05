/* __tcf_6 at 0x802D01F0 (44B) — auto-matched [load_addr_param_44B] */

// FLAGS: -fno-elide-constructors
extern int g_obj_802D01F0[];
extern int func_802D01F0(int, int);

int fwd_802D01F0(void *self) {
    return func_802D01F0((int)g_obj_802D01F0, 2);
}
