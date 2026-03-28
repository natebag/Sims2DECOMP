struct AptAllocator;
extern AptAllocator* gpAptAllocator;

void AptAllocator_Free(AptAllocator* alloc, void* ptr, unsigned int size);

struct AptActionQueueC {
    void operator delete(void* ptr, unsigned int size);
};

void AptActionQueueC::operator delete(void* ptr, unsigned int size) {
    AptAllocator_Free(gpAptAllocator, ptr, size);
}
