struct AptTextAllocator;
extern AptTextAllocator* gpAptTextAllocator;

void* AptTextAllocator_Alloc(AptTextAllocator* alloc, unsigned int size);

struct AptTextFormat {
    void* operator new(unsigned int size);
};

void* AptTextFormat::operator new(unsigned int size) {
    return AptTextAllocator_Alloc(gpAptTextAllocator, size);
}
