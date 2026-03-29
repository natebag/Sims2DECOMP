struct DOGMA_PoolManager {
    void* Allocate(unsigned int size);
};

extern DOGMA_PoolManager* spAptPoolManager;

struct AptInteger {
    void* operator new(unsigned int size);
};

void* AptInteger::operator new(unsigned int size)
{
    return spAptPoolManager->Allocate(size);
}
