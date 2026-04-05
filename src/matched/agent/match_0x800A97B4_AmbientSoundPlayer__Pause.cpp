/* AmbientSoundPlayer::Pause(void) at 0x800A97B4 (68B) */

struct PVt { char pad[0x38]; short m_off; char _p[2]; int (*m_fn)(void *); };
struct PImpl { PVt *m_vt; };

struct AmbSndPause {
    char pad[0x08];
    PImpl *m_impl;
    int Pause(void);
};

int AmbSndPause::Pause(void) {
    PImpl *impl = m_impl;
    if (impl != 0) {
        PVt *vt = impl->m_vt;
        short off = vt->m_off;
        int (*fn)(void *) = vt->m_fn;
        fn((char *)impl + off);
    }
    return 1;
}
