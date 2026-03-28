// 0x80371A90 (8 bytes) - OSGetSemaphoreCount
// lwz r3, 0(r3); blr

typedef struct OSSemaphore {
    int count;
} OSSemaphore;

int OSGetSemaphoreCount(OSSemaphore* sem) {
    return sem->count;
}
