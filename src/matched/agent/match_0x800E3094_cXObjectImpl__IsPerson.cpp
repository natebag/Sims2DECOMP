/* cXObjectImpl::IsPerson(void) at 0x800E3094 (68B) */

struct PersonVt { char pad[0x318]; short m_off; int (*m_fn)(void *); };
struct PersonInner2 { char pad[0x04]; PersonVt *m_vt; };
struct cXObjectImpl_IP { char pad[0x04]; PersonInner2 *m_inner; int IsPerson(void); };

int cXObjectImpl_IP::IsPerson(void) {
    PersonInner2 *inner = m_inner;
    PersonVt *vt = inner->m_vt;
    short off = vt->m_off;
    int (*fn)(void *) = vt->m_fn;
    return fn((char *)inner + off) == 2;
}
