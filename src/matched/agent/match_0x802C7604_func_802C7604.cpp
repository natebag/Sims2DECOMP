/* auto at 0x802C7604 (36B) [wrapper_deref_call] */

struct W_802C7604 { char pad[0x0]; void *m_ptr; };
extern int wrap_802C7604(void *);
int func_802C7604(W_802C7604 *self) { return wrap_802C7604(self->m_ptr); }
