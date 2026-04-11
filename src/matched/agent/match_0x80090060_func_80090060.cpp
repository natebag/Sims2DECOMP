/* auto at 0x80090060 (8B) [setter_8B] */

struct SS_80090060 { char pad[0x0C]; int m_val; };
void func_80090060(SS_80090060 *self, int val) { self->m_val = val; }
