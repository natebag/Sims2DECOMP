struct AptAllocator;
extern AptAllocator* gpAptAllocator2;

void AptAllocator_Free2(AptAllocator* alloc, void* ptr, unsigned int size);

struct AptPseudoData_t2 {
    void operator delete(void* ptr, unsigned int size);
};

void AptPseudoData_t2::operator delete(void* ptr, unsigned int size) {
    AptAllocator_Free2(gpAptAllocator2, ptr, size);
}
