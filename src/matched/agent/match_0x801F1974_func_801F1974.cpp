/* auto at 0x801F1974 (40B) [deref_self_call] */

struct S_801F1974 { char pad[0x04]; void *m_inner; };
extern int func_801F1974(void *, S_801F1974 *);
int func_801F1974(S_801F1974 *self) {
    return func_801F1974(self->m_inner, self);
}
