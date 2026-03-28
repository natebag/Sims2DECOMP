/* cXPortal::setPortalImpl(cXPortalImpl *) - 0x80132730 - 20 bytes */
/* lwz r9, 0(r3); lwz r11, 0(r9); lwz r10, 0(r11); stw r4, 0xC(r10); blr */

class cXPortalImpl;

struct PortalInner3 {
    char _pad[0xC];
    cXPortalImpl* m_impl;
};

struct PortalInner2 {
    PortalInner3* m_inner3;
};

struct PortalInner1 {
    PortalInner2* m_inner2;
};

class cXPortal {
public:
    PortalInner1* m_inner1;

    void setPortalImpl(cXPortalImpl *impl);
};

void cXPortal::setPortalImpl(cXPortalImpl *impl) {
    PortalInner1* p1 = m_inner1;
    PortalInner2* p2 = p1->m_inner2;
    PortalInner3* p3 = p2->m_inner3;
    p3->m_impl = impl;
}
