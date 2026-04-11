/* auto at 0x802D7B20 (36B) [wrapper_deref_call] */

struct W_802D7B20 { char pad[0x4]; void *m_ptr; };
extern int wrap_802D7B20(void *);
int func_802D7B20(W_802D7B20 *self) { return wrap_802D7B20(self->m_ptr); }
