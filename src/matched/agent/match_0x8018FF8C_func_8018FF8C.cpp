/* auto at 0x8018FF8C (36B) [wrapper_deref_call] */

struct W_8018FF8C { char pad[0x118]; void *m_ptr; };
extern int wrap_8018FF8C(void *);
int func_8018FF8C(W_8018FF8C *self) { return wrap_8018FF8C(self->m_ptr); }
