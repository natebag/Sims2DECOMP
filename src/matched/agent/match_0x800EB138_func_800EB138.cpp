/* auto at 0x800EB138 (36B) [wrapper_deref_call] */

struct W_800EB138 { char pad[0x8C]; void *m_ptr; };
extern int wrap_800EB138(void *);
int func_800EB138(W_800EB138 *self) { return wrap_800EB138(self->m_ptr); }
