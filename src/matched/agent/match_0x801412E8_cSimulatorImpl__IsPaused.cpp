/* cSimulatorImpl::IsPaused(void) at 0x801412E8 (52B) */

struct Vt_cSimulatorImpl_IsPaused { char pad[0x70]; short m_off; int (*m_fn)(void *); };
struct S_cSimulatorImpl_IsPaused { Vt_cSimulatorImpl_IsPaused *m_vt; int func(); };

int S_cSimulatorImpl_IsPaused::func() {
    Vt_cSimulatorImpl_IsPaused *vt = m_vt;
    short off = vt->m_off;
    return vt->m_fn((char *)this + off);
}
