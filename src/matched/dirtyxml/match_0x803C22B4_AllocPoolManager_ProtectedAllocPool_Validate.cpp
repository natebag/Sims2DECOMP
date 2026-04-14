/* AllocPoolManager<ProtectedAllocPool>::Validate(void) - 0x803C22B4 (64 bytes) */

struct ProtectedAllocPool {
    char data[52];
    void Valid();
};

struct AllocPoolManager_ProtectedAllocPool {
    char header[8];
    ProtectedAllocPool pools[8];

    void Validate();
};

void AllocPoolManager_ProtectedAllocPool::Validate()
{
    ProtectedAllocPool *p = &pools[0];
    int i = 8;
    do {
        p->Valid();
        p++;
    } while (--i);
}
