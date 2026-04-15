/* cXMTObject::setPortalImpl(cXPortalImpl *) - 0x800C7CC0 (16 bytes) */

struct cXPortalImpl;

struct cXMTObjectInner {
    char pad[12];
    cXPortalImpl* m_portal;  // +12
};

class cXMTObject {
public:
    cXMTObjectInner* m_inner;  // +0 (double-deref: *((*this)->m_portal) pattern)

    void setPortalImpl(cXPortalImpl* portal);
};

void cXMTObject::setPortalImpl(cXPortalImpl* portal) {
    cXMTObjectInner** pp = (cXMTObjectInner**)m_inner;  // lwz r9, 0(r3)
    cXMTObjectInner* p = *pp;                            // lwz r11, 0(r9)
    p->m_portal = portal;                                // stw r4, 12(r11)
}
