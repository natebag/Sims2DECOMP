// 0x802E1574 ESingleLock::ESingleLock(ESyncObject*, bool, bool) (76 B)
// FLAGS:
//
// Scoped single-lock helper ctor. Stores the target sync object, clears the
// "currently held" flag, records whether the lock should auto-release, and (if
// asked to lock now) immediately acquires it with an infinite timeout.

struct ESyncObject;

struct ESingleLock {
    ESyncObject* m_sync;        // 0x00
    int          m_locked;      // 0x04
    int          m_autoRelease; // 0x08
    ESingleLock(ESyncObject* sync, bool lockNow, bool autoRelease);
    void Lock(unsigned int timeout);
};

ESingleLock::ESingleLock(ESyncObject* sync, bool lockNow, bool autoRelease)
{
    m_sync = sync;
    m_locked = 0;
    m_autoRelease = autoRelease;
    if (lockNow)
        Lock((unsigned int)-1);
}
