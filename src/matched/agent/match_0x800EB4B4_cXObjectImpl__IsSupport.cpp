/* cXObjectImpl::IsSupport(void) at 0x800EB4B4 (68B) */

struct SupportVt { char pad[0x3F8]; short m_off; int (*m_fn)(void *); };
struct SupportInner { char pad[0x04]; SupportVt *m_vt; };
struct cXObjectImpl_IS { char pad[0x04]; SupportInner *m_inner; int IsSupport(void); };

int cXObjectImpl_IS::IsSupport(void) {
    SupportInner *inner = m_inner;
    SupportVt *vt = inner->m_vt;
    short off = vt->m_off;
    int (*fn)(void *) = vt->m_fn;
    return fn((char *)inner + off) == 6;
}
