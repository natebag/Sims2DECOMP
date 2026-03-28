struct Semaphore_A {
    void Acquire(unsigned int timeout);
};
struct EMutex_A {
    char pad[0x04];
    Semaphore_A m_sem;
    void Acquire(unsigned int timeout);
};
void EMutex_A::Acquire(unsigned int timeout) {
    m_sem.Acquire(timeout);
}
