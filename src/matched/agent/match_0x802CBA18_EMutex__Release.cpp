struct ESemaphore {
    void Release();
};

struct EMutex {
    char _pad[0x04];
    ESemaphore m_sem;

    void Release();
};

void EMutex::Release()
{
    m_sem.Release();
}
