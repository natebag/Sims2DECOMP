struct DOGMA_PoolManager {
    void Deallocate(void* ptr, unsigned int size);
};

extern DOGMA_PoolManager* spAptPoolManager;

struct AptBoolean {
    void operator delete(void* ptr, unsigned int size);
};

void AptBoolean::operator delete(void* ptr, unsigned int size)
{
    spAptPoolManager->Deallocate(ptr, size);
}
