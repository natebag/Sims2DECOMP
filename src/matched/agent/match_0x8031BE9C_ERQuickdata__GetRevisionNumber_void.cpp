/* ERQuickdata__GetRevisionNumber_void at 0x8031BE9C (24B) — auto-matched [null_deref_ret_24B] */

struct Inner_8031BE9C { char pad[0x0C]; int m_val; };
struct S_8031BE9C { char pad[0x14]; Inner_8031BE9C *m_ptr; };
int func_8031BE9C(S_8031BE9C *self) {
    Inner_8031BE9C *p = self->m_ptr;
    if (!p) return 0;
    return p->m_val;
}
