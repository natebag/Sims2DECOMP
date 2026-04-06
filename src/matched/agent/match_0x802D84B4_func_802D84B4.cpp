/* auto at 0x802D84B4 (36B) [wrapper_deref_call] */

struct W_802D84B4 { char pad[0x318]; void *m_ptr; };
extern int wrap_802D84B4(void *);
int func_802D84B4(W_802D84B4 *self) { return wrap_802D84B4(self->m_ptr); }
