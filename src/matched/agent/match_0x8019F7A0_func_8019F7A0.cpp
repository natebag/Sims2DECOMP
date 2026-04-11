/* auto at 0x8019F7A0 (40B) [load_addr_call_40B] */

// FLAGS: -fno-elide-constructors
extern int g_obj_8019F7A0[];
extern void func_8019F7A0(void *);

void load_call_8019F7A0(void) {
    func_8019F7A0(g_obj_8019F7A0);
}
