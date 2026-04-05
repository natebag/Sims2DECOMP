/* ESingleLock::Lock(unsigned int) at 0x802E160C (72B) */

struct LkVt { char pad[0x10]; short m_off; char _p[2]; int (*m_fn)(void *, unsigned int); };
struct LkImpl { LkVt *m_vt; };

struct ESingleLockL {
    LkImpl *m_mutex;
    int m_lockResult;
    void Lock(unsigned int lockVal);
};

void ESingleLockL::Lock(unsigned int lockVal) {
    LkImpl *impl = m_mutex;
    LkVt *vt = impl->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, unsigned int) = vt->m_fn;
    m_lockResult = fn((char *)impl + off, lockVal);
}
