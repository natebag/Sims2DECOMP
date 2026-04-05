/* ENgcRC__SetAlpha_float at 0x8033AFBC (40B) — auto-matched [load_addr_call_40B] */

// FLAGS: -fno-elide-constructors
extern int g_obj_8033AFBC[];
extern void func_8033AFBC(void *);

void load_call_8033AFBC(void) {
    func_8033AFBC(g_obj_8033AFBC);
}
