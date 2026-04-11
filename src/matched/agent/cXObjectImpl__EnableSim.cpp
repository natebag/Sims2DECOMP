// FLAGS: -fno-elide-constructors
/* cXObjectImpl::EnableSim(bool) at 0x800EAFC0 (68B) */

struct ESVt { char pad[0x240]; short m_off; char _p[2]; int (*m_fn)(void *, short, int, int); };
struct ESImpl { ESVt *m_vt; };

struct cXObjES {
    char pad1[0x58];
    ESImpl *m_impl;
    char pad2[0x08];
    short m_index;

    int EnableSim(int enabled);
};

int cXObjES::EnableSim(int enabled) {
    ESImpl *impl = m_impl;
    short idx = m_index;
    ESVt *vt = impl->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, short, int, int) = vt->m_fn;
    return fn((char *)impl + off, idx, 1, enabled);
}
