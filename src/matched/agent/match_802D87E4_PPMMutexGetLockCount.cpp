struct PPMMutex {
    char pad[0x0C];
    int m_lockCount;
};
int PPMMutexGetLockCount(void* mutex) {
    return ((PPMMutex*)mutex)->m_lockCount;
}
