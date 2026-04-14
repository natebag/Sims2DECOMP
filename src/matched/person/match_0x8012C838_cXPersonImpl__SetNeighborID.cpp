/* cXPersonImpl::SetNeighborID(short) at 0x8012C838 (64B) */

struct PersonInnerVtable {
    char pad[0x140];
    short m_vbaseOff;
    int (*m_setNeighborFunc)(void *, int, short);
};

struct PersonInner {
    char pad[0x04];
    PersonInnerVtable *m_vtable;
};

struct cXPersonImpl {
    char pad[0x04];
    PersonInner *m_inner;

    void SetNeighborID(short id);
};

void cXPersonImpl::SetNeighborID(short id) {
    PersonInner *inner = m_inner;
    PersonInnerVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, int, short) = vt->m_setNeighborFunc;
    fn((char *)inner + off, 31, id);
}
