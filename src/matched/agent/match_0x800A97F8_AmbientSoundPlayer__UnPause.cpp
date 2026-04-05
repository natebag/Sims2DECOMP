/* AmbientSoundPlayer::UnPause(void) at 0x800A97F8 (68B) */

struct UPVt { char pad[0x40]; short m_off; char _p[2]; int (*m_fn)(void *); };
struct UPImpl { UPVt *m_vt; };

struct AmbSndUnPause {
    char pad[0x08];
    UPImpl *m_impl;
    int UnPause(void);
};

int AmbSndUnPause::UnPause(void) {
    UPImpl *impl = m_impl;
    if (impl != 0) {
        UPVt *vt = impl->m_vt;
        short off = vt->m_off;
        int (*fn)(void *) = vt->m_fn;
        fn((char *)impl + off);
    }
    return 1;
}
