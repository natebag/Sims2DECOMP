struct DOGMA_PoolManager {
    void* Allocate(unsigned int size);
};

extern DOGMA_PoolManager* spAptPoolManager;

struct AptBoolean {
    void* operator new(unsigned int size);
};

void* AptBoolean::operator new(unsigned int size)
{
    return spAptPoolManager->Allocate(size);
}
