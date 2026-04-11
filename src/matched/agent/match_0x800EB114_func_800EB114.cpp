/* auto at 0x800EB114 (36B) [wrapper_deref_call] */

struct W_800EB114 { char pad[0x8C]; void *m_ptr; };
extern int wrap_800EB114(void *);
int func_800EB114(W_800EB114 *self) { return wrap_800EB114(self->m_ptr); }
