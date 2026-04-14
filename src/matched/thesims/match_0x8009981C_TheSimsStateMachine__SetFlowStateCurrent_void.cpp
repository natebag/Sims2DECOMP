/* TheSimsStateMachine__SetFlowStateCurrent_void at 0x8009981C (24B) — auto-matched [null_field_copy_24B] */

struct Inner_8009981C { char p1[0x84]; int m_src; char p2[0x00]; int m_dst; };
struct S_8009981C { char pad[0x98]; Inner_8009981C *m_ptr; };
void func_8009981C(S_8009981C *self) {
    Inner_8009981C *p = self->m_ptr;
    if (!p) return;
    p->m_dst = p->m_src;
}
