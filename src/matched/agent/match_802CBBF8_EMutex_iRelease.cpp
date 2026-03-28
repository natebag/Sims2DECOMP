struct Semaphore_iR {
    void iRelease();
};
struct EMutex_iR {
    char pad[0x04];
    Semaphore_iR m_sem;
    void iRelease();
};
void EMutex_iR::iRelease() {
    m_sem.iRelease();
}
