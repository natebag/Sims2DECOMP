// 0x802E15C0 ESingleLock::~ESingleLock (76B)
// dtor: if (m_field8) Unlock(); delete-flag check.

struct ESingleLock {
    char pad[8];
    int* m_field8;
    void Unlock();
    ~ESingleLock();
};

ESingleLock::~ESingleLock() {
    if (m_field8 != 0) Unlock();
}
