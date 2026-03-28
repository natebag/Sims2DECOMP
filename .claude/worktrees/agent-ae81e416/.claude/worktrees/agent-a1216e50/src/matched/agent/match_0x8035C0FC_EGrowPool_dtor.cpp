/* EGrowPool::~EGrowPool(void) - 0x8035C0FC (64 bytes) */

struct EGrowPool {
    void Cleanup();
    ~EGrowPool();
};

EGrowPool::~EGrowPool()
{
    Cleanup();
}
