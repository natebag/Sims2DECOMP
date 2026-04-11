/* EMutex::Acquire(char *, int, unsigned int) at 0x802CB9BC (56B) */

struct MtxAcqVt { char pad[0x10]; short m_off; int (*m_fn)(void *, unsigned int, int); };
struct EMutex_A { MtxAcqVt *m_vt; void Acquire(char *name, int timeout, unsigned int flags); };

void EMutex_A::Acquire(char *name, int timeout, unsigned int flags) {
    MtxAcqVt *vt = m_vt;
    short off = vt->m_off;
    int (*fn)(void *, unsigned int, int) = vt->m_fn;
    fn((char *)this + off, flags, timeout);
}
