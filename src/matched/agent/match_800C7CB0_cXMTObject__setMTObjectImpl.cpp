/* cXMTObject::setMTObjectImpl(cXMTObjectImpl *) - 0x800C7CB0 (16 bytes) */

struct cXMTObjectImpl;

struct InnerObj {
    int m_pad0;
    int m_pad4;
    cXMTObjectImpl *m_mtObjectImpl;
};

struct OuterObj {
    InnerObj *m_inner;
};

struct cXMTObject {
    OuterObj *m_outer;

    void setMTObjectImpl(cXMTObjectImpl *impl);
};

void cXMTObject::setMTObjectImpl(cXMTObjectImpl *impl) {
    m_outer->m_inner->m_mtObjectImpl = impl;
}
