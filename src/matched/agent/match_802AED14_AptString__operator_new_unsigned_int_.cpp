struct AptAllocator;
extern AptAllocator* gpAptAllocator;

void* AptAllocator_Alloc(AptAllocator* alloc, unsigned int size);

struct AptString {
    void* operator new(unsigned int size);
};

void* AptString::operator new(unsigned int size) {
    return AptAllocator_Alloc(gpAptAllocator, size);
}
