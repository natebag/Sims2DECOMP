/* auto at 0x800EB304 (36B) [wrapper_deref_call] */

struct W_800EB304 { char pad[0x8C]; void *m_ptr; };
extern int wrap_800EB304(void *);
int func_800EB304(W_800EB304 *self) { return wrap_800EB304(self->m_ptr); }
