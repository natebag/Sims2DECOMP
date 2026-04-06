/* auto at 0x801F1DDC (40B) [deref_self_call] */

struct S_801F1DDC { char pad[0x04]; void *m_inner; };
extern int func_801F1DDC(void *, S_801F1DDC *);
int func_801F1DDC(S_801F1DDC *self) {
    return func_801F1DDC(self->m_inner, self);
}
