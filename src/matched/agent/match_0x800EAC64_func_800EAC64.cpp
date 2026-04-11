/* auto at 0x800EAC64 (36B) [wrapper_deref_call] */

struct W_800EAC64 { char pad[0x8C]; void *m_ptr; };
extern int wrap_800EAC64(void *);
int func_800EAC64(W_800EAC64 *self) { return wrap_800EAC64(self->m_ptr); }
