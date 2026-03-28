/* EILight::Init(void) at 0x80227C5C (52B) */

struct Vt_EILight_Init { char pad[0x160]; short m_off; int (*m_fn)(void *); };
struct S_EILight_Init { Vt_EILight_Init *m_vt; void func(); };

void S_EILight_Init::func() {
    Vt_EILight_Init *vt = m_vt;
    short off = vt->m_off;
        vt->m_fn((char *)this + off);
}
