/* auto at 0x801F1B6C (40B) [deref_self_call] */

struct S_801F1B6C { char pad[0x04]; void *m_inner; };
extern int func_801F1B6C(void *, S_801F1B6C *);
int func_801F1B6C(S_801F1B6C *self) {
    return func_801F1B6C(self->m_inner, self);
}
