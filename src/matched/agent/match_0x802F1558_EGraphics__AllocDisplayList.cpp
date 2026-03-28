/* EGraphics::AllocDisplayList(RCMode) at 0x802F1558 (52B) */

struct Vt_EGraphics_AllocDisplayList { char pad[0x1C8]; short m_off; int (*m_fn)(void *, int); };
struct S_EGraphics_AllocDisplayList { Vt_EGraphics_AllocDisplayList *m_vt; int func(int mode); };

int S_EGraphics_AllocDisplayList::func(int mode) {
    Vt_EGraphics_AllocDisplayList *vt = m_vt;
    short off = vt->m_off;
    return vt->m_fn((char *)this + off, mode);
}
