/* auto at 0x802E07A0 (36B) [field_extra_param_call] */

struct S_802E07A0 { char pad[0x04]; int m_val; };
extern int wrap_802E07A0(void *, int, int);
int func_802E07A0(S_802E07A0 *self, int a0) { return wrap_802E07A0(self, a0, self->m_val); }
