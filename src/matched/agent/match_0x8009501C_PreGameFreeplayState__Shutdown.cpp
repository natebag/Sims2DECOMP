/* PreGameFreeplayState::Shutdown(void) at 0x8009501C (68B) */

struct SDVt { char pad[0x08]; short m_off; char _p[2]; int (*m_fn)(void *, int); };
struct SDSub { char pad[0x80]; SDVt *m_vt; };

struct PreGameFPS {
    char pad[0x1C];
    SDSub *m_impl;
    void Shutdown(void);
};

void PreGameFPS::Shutdown(void) {
    SDSub *impl = m_impl;
    if (impl != 0) {
        SDVt *vt = impl->m_vt;
        short off = vt->m_off;
        int (*fn)(void *, int) = vt->m_fn;
        fn((char *)impl + off, 3);
    }
}
