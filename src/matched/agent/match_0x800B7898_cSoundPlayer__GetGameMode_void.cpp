/* cSoundPlayer__GetGameMode_void at 0x800B7898 (24B) — auto-matched [null_deref_sda_ret_24B] */

struct Inner_800B7898 { char pad[0x30]; int m_val; };
extern Inner_800B7898 *g_ptr_800B7898;
int func_800B7898(void) {
    Inner_800B7898 *p = g_ptr_800B7898;
    if (!p) return 3;
    return p->m_val;
}
