/* auto at 0x8018FFBC (36B) [wrapper_deref_call] */

struct W_8018FFBC { char pad[0x118]; void *m_ptr; };
extern int wrap_8018FFBC(void *);
int func_8018FFBC(W_8018FFBC *self) { return wrap_8018FFBC(self->m_ptr); }
