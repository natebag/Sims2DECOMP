/* __tcf_0_15 at 0x8032F6FC (44B) — auto-matched [load_addr_param_44B] */

// FLAGS: -fno-elide-constructors
extern int g_obj_8032F6FC[];
extern int func_8032F6FC(int, int);

int fwd_8032F6FC(void *self) {
    return func_8032F6FC((int)g_obj_8032F6FC, 2);
}
