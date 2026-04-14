/* cXPersonImpl::SetAwareOfObjectKilled(cXObject *) at 0x8012CAE0 (56B) */

struct AwareKVt { char pad[0x128]; short m_off; int (*m_fn)(void *, void *); };
struct AwareKObj { AwareKVt *m_vt; };
struct cXPersonImpl_SAOK { char pad[0x3F4]; AwareKObj *m_inner; void SetAwareOfObjectKilled(void *obj); };

void cXPersonImpl_SAOK::SetAwareOfObjectKilled(void *obj) {
    AwareKObj *inner = m_inner;
    AwareKVt *vt = inner->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, void *) = vt->m_fn;
    fn((char *)inner + off, obj);
}
