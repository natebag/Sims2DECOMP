struct ESemaphore {
    void Acquire(unsigned int timeout);
};

struct EMutex {
    char _pad[0x04];
    ESemaphore m_sem;

    void Acquire(unsigned int timeout);
};

void EMutex::Acquire(unsigned int timeout)
{
    m_sem.Acquire(timeout);
}
