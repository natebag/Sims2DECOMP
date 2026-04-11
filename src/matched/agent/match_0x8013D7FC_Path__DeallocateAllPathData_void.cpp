/* Path__DeallocateAllPathData_void at 0x8013D7FC (40B) — auto-matched [load_addr_call_40B] */

// FLAGS: -fno-elide-constructors
extern int g_obj_8013D7FC[];
extern void func_8013D7FC(void *);

void load_call_8013D7FC(void) {
    func_8013D7FC(g_obj_8013D7FC);
}
