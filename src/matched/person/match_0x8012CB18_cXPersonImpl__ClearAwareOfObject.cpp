/* cXPersonImpl::ClearAwareOfObject(cXObject *) at 0x8012CB18 (56B) */

struct ClearAVt { char pad[0x130]; short m_off; int (*m_fn)(void *, void *); };
struct ClearAObj { ClearAVt *m_vt; };
struct cXPersonImpl_CAO { char pad[0x3F4]; ClearAObj *m_inner; void ClearAwareOfObject(void *obj); };

void cXPersonImpl_CAO::ClearAwareOfObject(void *obj) {
    ClearAObj *inner = m_inner;
    ClearAVt *vt = inner->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, void *) = vt->m_fn;
    fn((char *)inner + off, obj);
}
