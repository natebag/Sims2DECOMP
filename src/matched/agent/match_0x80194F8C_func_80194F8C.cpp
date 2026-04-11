/* auto at 0x80194F8C (36B) [field_extra_param_call] */

struct S_80194F8C { char pad[0x98]; int m_val; };
extern int wrap_80194F8C(void *, int);
int func_80194F8C(S_80194F8C *self) { return wrap_80194F8C(self, self->m_val); }
