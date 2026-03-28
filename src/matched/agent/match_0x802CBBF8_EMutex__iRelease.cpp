struct ESemaphore {
    void iRelease();
};

struct EMutex {
    char _pad[0x04];
    ESemaphore m_sem;

    void iRelease();
};

void EMutex::iRelease()
{
    m_sem.iRelease();
}
