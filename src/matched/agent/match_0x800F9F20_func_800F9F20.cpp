/* auto at 0x800F9F20 (36B) [wrapper_deref_call] */

struct W_800F9F20 { char pad[0x0]; void *m_ptr; };
extern int wrap_800F9F20(void *);
int func_800F9F20(W_800F9F20 *self) { return wrap_800F9F20(self->m_ptr); }
