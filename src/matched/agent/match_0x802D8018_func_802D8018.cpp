/* auto at 0x802D8018 (36B) [wrapper_deref_call] */

struct W_802D8018 { char pad[0x2C]; void *m_ptr; };
extern int wrap_802D8018(void *);
int func_802D8018(W_802D8018 *self) { return wrap_802D8018(self->m_ptr); }
