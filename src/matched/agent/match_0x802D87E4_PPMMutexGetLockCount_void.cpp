// 0x802D87E4 PPMMutexGetLockCount(void) (8 B)
struct PPMMutex { char _pad[0xc]; unsigned m_lockCount; };
unsigned PPMMutexGetLockCount(PPMMutex* mutex) { return mutex->m_lockCount; }
