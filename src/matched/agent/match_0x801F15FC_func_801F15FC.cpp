/* auto at 0x801F15FC (40B) [deref_self_call] */

struct S_801F15FC { char pad[0x04]; void *m_inner; };
extern int func_801F15FC(void *, S_801F15FC *);
int func_801F15FC(S_801F15FC *self) {
    return func_801F15FC(self->m_inner, self);
}
