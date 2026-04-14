/* ObjSelector::loadFile(void) at 0x80110790 (76B) */

struct LFVt { char pad[0x148]; short m_off; char _p[2]; int (*m_fn)(void *, void *); };
struct LFImpl { LFVt *m_vt; };

struct ObjSelectorLF {
    int m_result;
    char pad[0x4C];
    LFImpl *m_impl;
    int loadFile(void);
};

int ObjSelectorLF::loadFile(void) {
    LFImpl *impl = m_impl;
    LFVt *vt = impl->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, void *) = vt->m_fn;
    fn((char *)impl + off, this);
    return m_result;
}
