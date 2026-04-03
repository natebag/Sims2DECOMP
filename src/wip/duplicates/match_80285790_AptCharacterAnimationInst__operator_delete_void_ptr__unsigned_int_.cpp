struct AptAllocator;
extern AptAllocator* gpAptAllocator;

void AptAllocator_Free(AptAllocator* alloc, void* ptr, unsigned int size);

struct AptCharacterAnimationInst {
    void operator delete(void* ptr, unsigned int size);
};

void AptCharacterAnimationInst::operator delete(void* ptr, unsigned int size) {
    AptAllocator_Free(gpAptAllocator, ptr, size);
}
