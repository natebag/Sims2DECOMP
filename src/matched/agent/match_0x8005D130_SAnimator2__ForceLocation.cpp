/* SAnimator2::ForceLocation(void) at 0x8005D130 (52B) */

struct Vt_SAnimator2_ForceLocation { char pad[0x38]; short m_off; int (*m_fn)(void *); };
struct S_SAnimator2_ForceLocation { Vt_SAnimator2_ForceLocation *m_vt; void func(); };

void S_SAnimator2_ForceLocation::func() {
    Vt_SAnimator2_ForceLocation *vt = m_vt;
    short off = vt->m_off;
        vt->m_fn((char *)this + off);
}
