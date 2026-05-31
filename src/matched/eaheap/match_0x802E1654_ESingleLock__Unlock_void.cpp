// 0x802E1654 ESingleLock::Unlock(void) (96 B)
// FLAGS:
//
// Release the held lock: if currently held, virtually dispatch the sync
// object's Unlock (ESyncObject vtable slot 3) and record !success into the held
// flag. Returns !held (true once the lock is no longer held).

struct ESyncObject {
    virtual ~ESyncObject();
    virtual void Lock(int timeout);
    virtual bool Unlock();
};

struct ESingleLock {
    ESyncObject* m_sync;        // 0x00
    bool         m_locked;      // 0x04
    bool         m_autoRelease; // 0x08
    bool Unlock();
};

bool ESingleLock::Unlock()
{
    if (m_locked)
        m_locked = !m_sync->Unlock();
    return !m_locked;
}
