/* AptCIH::PreDestroy(void) at 0x8028FFEC (80B) */

struct ACVt { char pad[0x08]; short m_off; char _p[2]; int (*m_fn)(void *); };
struct ACSub { char pad[0x14]; ACVt *m_vt; };

struct AptCIH_PD {
    char pad[0x4C];
    ACSub *m_impl;
    void PreDestroy(void);
};

void AptCIH_PD::PreDestroy(void) {
    ACSub *impl = m_impl;
    if (impl != 0 && impl != (ACSub *)0xBAADF00D) {
        ACVt *vt = impl->m_vt;
        short off = vt->m_off;
        int (*fn)(void *) = vt->m_fn;
        fn((char *)impl + off);
    }
}
