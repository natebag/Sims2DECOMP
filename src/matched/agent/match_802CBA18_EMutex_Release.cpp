struct Semaphore_R {
    void Release();
};
struct EMutex_R {
    char pad[0x04];
    Semaphore_R m_sem;
    void Release();
};
void EMutex_R::Release() {
    m_sem.Release();
}
