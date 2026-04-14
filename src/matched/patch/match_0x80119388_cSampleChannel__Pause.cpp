/* cSampleChannel::Pause(void) at 0x80119388 (80B) */

struct CPVt { char pad[0x38]; short m_off; char _p[2]; int (*m_fn)(void *); };
struct CPImpl { CPVt *m_vt; };
struct CPOuter { char pad[0x18]; CPImpl *m_impl; };

struct cSampleChPause {
    CPOuter *m_outer;
    int Pause(void);
};

int cSampleChPause::Pause(void) {
    CPOuter *outer = m_outer;
    if (outer != 0) {
        CPImpl *impl = outer->m_impl;
        if (impl != 0) {
            CPVt *vt = impl->m_vt;
            short off = vt->m_off;
            int (*fn)(void *) = vt->m_fn;
            fn((char *)impl + off);
        }
    }
    return 1;
}
