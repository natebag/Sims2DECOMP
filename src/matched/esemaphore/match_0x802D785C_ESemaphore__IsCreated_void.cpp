// 0x802D785C ESemaphore::IsCreated(void) (24 B)
//
// Returns whether the semaphore has been created: the OS handle/id at +0x04 is
// non-zero once Create() succeeds. Written in if-true form so the "return 1"
// value is latched before the signed test (matches DOL's li r3,1 / cmpwi /
// bnelr).

struct ESemaphore {
    void*    m_vt;        // 0x00
    int      m_handle;    // 0x04  OS sync handle/id (set by Create)
    unsigned m_maxCount;  // 0x08
    unsigned m_curCount;  // 0x0C
    int IsCreated() const;
};

int ESemaphore::IsCreated() const
{
    if (m_handle != 0)
        return 1;
    return 0;
}
