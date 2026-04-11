/* auto at 0x802D2C24 (36B) [wrapper_deref_call] */

struct W_802D2C24 { char pad[0x0]; void *m_ptr; };
extern int wrap_802D2C24(void *);
int func_802D2C24(W_802D2C24 *self) { return wrap_802D2C24(self->m_ptr); }
