/* EYETarget__EyeToyUnplugCallback_int at 0x801E70FC (24B) — auto-matched [null_check_sda_store_24B] */

struct Target_801E70FC { char pad[0xB0]; int m_field; };
extern Target_801E70FC *g_ptr_801E70FC;
void func_801E70FC(void) {
    Target_801E70FC *p = g_ptr_801E70FC;
    if (!p) return;
    p->m_field = 1;
}
