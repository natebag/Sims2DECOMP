/* auto at 0x80311FD8 (40B) [deref_self_call] */

struct S_80311FD8 { char pad[0x04]; void *m_inner; };
extern int func_80311FD8(void *, S_80311FD8 *);
int func_80311FD8(S_80311FD8 *self) {
    return func_80311FD8(self->m_inner, self);
}
