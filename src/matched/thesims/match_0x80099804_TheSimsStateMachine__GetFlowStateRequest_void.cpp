/* TheSimsStateMachine__GetFlowStateRequest_void at 0x80099804 (24B) — auto-matched [null_deref_ret_24B] */

struct Inner_80099804 { char pad[0x84]; int m_val; };
struct S_80099804 { char pad[0x98]; Inner_80099804 *m_ptr; };
int func_80099804(S_80099804 *self) {
    Inner_80099804 *p = self->m_ptr;
    if (!p) return 0;
    return p->m_val;
}
