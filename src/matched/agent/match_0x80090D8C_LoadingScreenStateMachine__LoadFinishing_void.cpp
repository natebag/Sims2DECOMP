/* LoadingScreenStateMachine__LoadFinishing_void at 0x80090D8C (24B) — auto-matched [null_check_sda_store_24B] */

struct Target_80090D8C { char pad[0xA4]; int m_field; };
extern Target_80090D8C *g_ptr_80090D8C;
void func_80090D8C(void) {
    Target_80090D8C *p = g_ptr_80090D8C;
    if (!p) return;
    p->m_field = 1;
}
