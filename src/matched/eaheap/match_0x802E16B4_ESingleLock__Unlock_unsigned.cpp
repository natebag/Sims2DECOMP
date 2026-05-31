// 0x802E16B4 ESingleLock::Unlock(unsigned int, unsigned int*) (96 B)
// FLAGS:
//
// Conditional-release variant: if the lock is held, virtually dispatch the sync
// object's Release (ESyncObject vtable slot 4) forwarding both args, and record
// !success into the held flag. Returns !held. Mirrors Unlock(void) but routes
// to Release instead of Unlock.

struct ESyncObject {
    virtual ~ESyncObject();
    virtual void Lock(int timeout);
    virtual bool Unlock();
    virtual bool Release(unsigned int a, unsigned int* b);
};

struct ESingleLock {
    ESyncObject* m_sync;        // 0x00
    bool         m_locked;      // 0x04
    bool         m_autoRelease; // 0x08
    bool Unlock(unsigned int a, unsigned int* b);
};

bool ESingleLock::Unlock(unsigned int a, unsigned int* b)
{
    if (m_locked)
        m_locked = !m_sync->Release(a, b);
    return !m_locked;
}
