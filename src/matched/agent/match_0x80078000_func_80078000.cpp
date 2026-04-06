/* auto at 0x80078000 (8B) [float_setter] */

struct SF_80078000 { char pad[0x474]; float m_val; };
void func_80078000(SF_80078000 *self, float val) { self->m_val = val; }
