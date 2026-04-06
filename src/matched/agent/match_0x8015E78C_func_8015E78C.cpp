/* auto at 0x8015E78C (36B) [wrapper_deref_call] */

struct W_8015E78C { char pad[0x4]; void *m_ptr; };
extern int wrap_8015E78C(void *);
int func_8015E78C(W_8015E78C *self) { return wrap_8015E78C(self->m_ptr); }
