/* ENgcScheduler__Flush_void at 0x8034D9B8 (40B) — auto-matched [load_addr_call_40B] */

// FLAGS: -fno-elide-constructors
extern int g_obj_8034D9B8[];
extern void func_8034D9B8(void *);

void load_call_8034D9B8(void) {
    func_8034D9B8(g_obj_8034D9B8);
}
