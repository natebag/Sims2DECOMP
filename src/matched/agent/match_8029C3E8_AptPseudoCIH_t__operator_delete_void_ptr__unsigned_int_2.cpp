struct AptAllocator;
extern AptAllocator* gpAptAllocator3;

void AptAllocator_Free3(AptAllocator* alloc, void* ptr, unsigned int size);

struct AptPseudoCIH_t2 {
    void operator delete(void* ptr, unsigned int size);
};

void AptPseudoCIH_t2::operator delete(void* ptr, unsigned int size) {
    AptAllocator_Free3(gpAptAllocator3, ptr, size);
}
