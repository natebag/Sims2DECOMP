/* auto at 0x802D84D8 (36B) [wrapper_deref_call] */

struct W_802D84D8 { char pad[0x318]; void *m_ptr; };
extern int wrap_802D84D8(void *);
int func_802D84D8(W_802D84D8 *self) { return wrap_802D84D8(self->m_ptr); }
