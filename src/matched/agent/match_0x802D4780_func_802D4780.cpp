/* auto at 0x802D4780 (36B) [wrapper_deref_call] */

struct W_802D4780 { char pad[0x0]; void *m_ptr; };
extern int wrap_802D4780(void *);
int func_802D4780(W_802D4780 *self) { return wrap_802D4780(self->m_ptr); }
