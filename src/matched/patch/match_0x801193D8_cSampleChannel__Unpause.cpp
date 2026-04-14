/* cSampleChannel::Unpause(void) at 0x801193D8 (80B) */

struct CUVt { char pad[0x40]; short m_off; char _p[2]; int (*m_fn)(void *); };
struct CUImpl { CUVt *m_vt; };
struct CUOuter { char pad[0x18]; CUImpl *m_impl; };

struct cSampleChUnpause {
    CUOuter *m_outer;
    int Unpause(void);
};

int cSampleChUnpause::Unpause(void) {
    CUOuter *outer = m_outer;
    if (outer != 0) {
        CUImpl *impl = outer->m_impl;
        if (impl != 0) {
            CUVt *vt = impl->m_vt;
            short off = vt->m_off;
            int (*fn)(void *) = vt->m_fn;
            fn((char *)impl + off);
        }
    }
    return 1;
}
