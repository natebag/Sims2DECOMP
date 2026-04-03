struct Semaphore_iA {
    void iAcquire();
};
struct EMutex_iA {
    char pad[0x04];
    Semaphore_iA m_sem;
    void iAcquire();
};
void EMutex_iA::iAcquire() {
    m_sem.iAcquire();
}
