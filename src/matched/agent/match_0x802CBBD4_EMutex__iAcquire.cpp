struct ESemaphore {
    void iAcquire();
};

struct EMutex {
    char _pad[0x04];
    ESemaphore m_sem;

    void iAcquire();
};

void EMutex::iAcquire()
{
    m_sem.iAcquire();
}
