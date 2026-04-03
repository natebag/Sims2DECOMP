struct AptAllocator;
extern AptAllocator* gpAptAllocator;

void* AptAllocator_Alloc(AptAllocator* alloc, unsigned int size);

struct AptCharacterTextInst {
    void* operator new(unsigned int size);
};

void* AptCharacterTextInst::operator new(unsigned int size) {
    return AptAllocator_Alloc(gpAptAllocator, size);
}
