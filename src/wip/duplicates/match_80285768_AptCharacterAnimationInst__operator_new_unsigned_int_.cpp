struct AptAllocator;
extern AptAllocator* gpAptAllocator;

void* AptAllocator_Alloc(AptAllocator* alloc, unsigned int size);

struct AptCharacterAnimationInst {
    void* operator new(unsigned int size);
};

void* AptCharacterAnimationInst::operator new(unsigned int size) {
    return AptAllocator_Alloc(gpAptAllocator, size);
}
