/* AllocPoolManager<FastAllocPool>::Validate(void) - 0x803C2408 (64 bytes) */

struct FastAllocPool {
    char data[24];
    void Valid();
};

struct AllocPoolManager_FastAllocPool {
    char header[8];
    FastAllocPool pools[8];

    void Validate();
};

void AllocPoolManager_FastAllocPool::Validate()
{
    FastAllocPool *p = &pools[0];
    int i = 8;
    do {
        p->Valid();
        p++;
    } while (--i);
}
