struct OSSemaphore {
    int m_count;
};
int OSGetSemaphoreCount(OSSemaphore *sem);
int OSGetSemaphoreCount(OSSemaphore *sem) { return sem->m_count; }
