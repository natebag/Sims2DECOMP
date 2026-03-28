struct AptTextAllocator;
extern AptTextAllocator* gpAptTextAllocator;

void AptTextAllocator_Free(AptTextAllocator* alloc, void* ptr, unsigned int size);

struct AptTextFormat {
    void operator delete(void* ptr, unsigned int size);
};

void AptTextFormat::operator delete(void* ptr, unsigned int size) {
    AptTextAllocator_Free(gpAptTextAllocator, ptr, size);
}
