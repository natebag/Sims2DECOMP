/* AptXml::PreDestroy(void) at 0x802B9674 (88B) */

struct APDVt { char pad[0x08]; short m_off; char _p[2]; int (*m_fn)(void *, int); };
struct APDImpl { APDVt *m_vt; };

struct AptXmlPD {
    char pad[0x24];
    APDImpl *m_impl;
    void PreDestroy(void);
};

void AptXmlPD::PreDestroy(void) {
    APDImpl *impl = m_impl;
    if (impl != 0) {
        APDVt *vt = impl->m_vt;
        short off = vt->m_off;
        int (*fn)(void *, int) = vt->m_fn;
        fn((char *)impl + off, 3);
    }
    m_impl = 0;
}
