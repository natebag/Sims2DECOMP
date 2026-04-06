/* auto at 0x802D8464 (36B) [wrapper_deref_call] */

struct W_802D8464 { char pad[0x318]; void *m_ptr; };
extern int wrap_802D8464(void *);
int func_802D8464(W_802D8464 *self) { return wrap_802D8464(self->m_ptr); }
