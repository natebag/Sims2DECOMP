/* auto at 0x8018CCF4 (36B) [wrapper_deref_call] */

struct W_8018CCF4 { char pad[0x118]; void *m_ptr; };
extern int wrap_8018CCF4(void *);
int func_8018CCF4(W_8018CCF4 *self) { return wrap_8018CCF4(self->m_ptr); }
