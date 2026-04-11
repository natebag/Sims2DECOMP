/* ESemaphore::iAcquire(void) at 0x802D798C (56B) */

struct SemVt { char pad[0x10]; short m_off; int (*m_fn)(void *, int); };
struct ESemaphore_iA { SemVt *m_vt; void iAcquire(void); };

void ESemaphore_iA::iAcquire(void) {
    SemVt *vt = m_vt;
    short off = vt->m_off;
    int (*fn)(void *, int) = vt->m_fn;
    fn((char *)this + off, 0);
}
