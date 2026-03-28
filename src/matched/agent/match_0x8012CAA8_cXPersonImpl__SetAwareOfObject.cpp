/* cXPersonImpl::SetAwareOfObject(cXObject *) at 0x8012CAA8 (56B) */

struct AwareVt { char pad[0x120]; short m_off; int (*m_fn)(void *, void *); };
struct AwareObj { AwareVt *m_vt; };
struct cXPersonImpl_SAO { char pad[0x3F4]; AwareObj *m_inner; void SetAwareOfObject(void *obj); };

void cXPersonImpl_SAO::SetAwareOfObject(void *obj) {
    AwareObj *inner = m_inner;
    AwareVt *vt = inner->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, void *) = vt->m_fn;
    fn((char *)inner + off, obj);
}
