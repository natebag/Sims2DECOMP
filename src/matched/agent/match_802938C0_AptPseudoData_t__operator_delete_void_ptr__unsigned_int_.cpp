struct AptAllocator;
extern AptAllocator* gpAptAllocator;

void AptAllocator_Free(AptAllocator* alloc, void* ptr, unsigned int size);

struct AptPseudoData_t {
    void operator delete(void* ptr, unsigned int size);
};

void AptPseudoData_t::operator delete(void* ptr, unsigned int size) {
    AptAllocator_Free(gpAptAllocator, ptr, size);
}
