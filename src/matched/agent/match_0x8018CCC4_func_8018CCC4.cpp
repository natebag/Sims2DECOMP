/* auto at 0x8018CCC4 (36B) [wrapper_deref_call] */

struct W_8018CCC4 { char pad[0x118]; void *m_ptr; };
extern int wrap_8018CCC4(void *);
int func_8018CCC4(W_8018CCC4 *self) { return wrap_8018CCC4(self->m_ptr); }
