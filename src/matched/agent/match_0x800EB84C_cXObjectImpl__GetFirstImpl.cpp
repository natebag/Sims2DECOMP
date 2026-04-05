/* cXObjectImpl::GetFirstImpl(void) at 0x800EB84C (80B) */

struct GFVt1 { char pad[0x98]; short m_off; char _p[2]; int (*m_fn)(void *); };
struct GFImpl1 { GFVt1 *m_vt; };

struct GFVt2 { char pad[0x04]; char pad2[0x51C]; short m_off; char _p[2]; int (*m_fn)(void *); };
struct GFResult { char pad[0x04]; GFVt2 *m_vt; };

struct cXObjGF {
    char pad[0x58];
    GFImpl1 *m_impl;
    int GetFirstImpl(void);
};

int cXObjGF::GetFirstImpl(void) {
    GFImpl1 *impl = m_impl;
    GFVt1 *vt = impl->m_vt;
    short off = vt->m_off;
    int (*fn)(void *) = vt->m_fn;
    GFResult *result = (GFResult *)fn((char *)impl + off);
    GFVt2 *vt2 = result->m_vt;
    short off2 = vt2->m_off;
    int (*fn2)(void *) = vt2->m_fn;
    return fn2((char *)result + off2);
}
