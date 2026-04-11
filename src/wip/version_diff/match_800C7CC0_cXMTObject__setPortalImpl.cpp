/* cXMTObject::setPortalImpl(cXPortalImpl *) - 0x800C7CC0 (16 bytes) */

struct cXPortalImpl;

struct InnerObj2 {
    int m_pad0;
    int m_pad4;
    int m_pad8;
    cXPortalImpl *m_portalImpl;
};

struct OuterObj2 {
    InnerObj2 *m_inner;
};

struct cXMTObject {
    OuterObj2 *m_outer;

    void setPortalImpl(cXPortalImpl *impl);
};

void cXMTObject::setPortalImpl(cXPortalImpl *impl) {
    m_outer->m_inner->m_portalImpl = impl;
}
