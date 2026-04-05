/* StartScreenVars::Shutdown(void) at 0x80095570 (68B) */

struct SSVt { char pad[0x08]; short m_off; char _p[2]; int (*m_fn)(void *, int); };
struct SSSub { char pad[0x9C]; SSVt *m_vt; };

struct StartScreenVS {
    char pad[0x20];
    SSSub *m_impl;
    void Shutdown(void);
};

void StartScreenVS::Shutdown(void) {
    SSSub *impl = m_impl;
    if (impl != 0) {
        SSVt *vt = impl->m_vt;
        short off = vt->m_off;
        int (*fn)(void *, int) = vt->m_fn;
        fn((char *)impl + off, 3);
    }
}
