/* auto at 0x801AD544 (36B) [wrapper_deref_call] */

struct W_801AD544 { char pad[0xC0]; void *m_ptr; };
extern int wrap_801AD544(void *);
int func_801AD544(W_801AD544 *self) { return wrap_801AD544(self->m_ptr); }
