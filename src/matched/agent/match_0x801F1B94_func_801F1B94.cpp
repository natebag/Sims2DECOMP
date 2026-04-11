/* auto at 0x801F1B94 (40B) [deref_self_call] */

struct S_801F1B94 { char pad[0x04]; void *m_inner; };
extern int func_801F1B94(void *, S_801F1B94 *);
int func_801F1B94(S_801F1B94 *self) {
    return func_801F1B94(self->m_inner, self);
}
