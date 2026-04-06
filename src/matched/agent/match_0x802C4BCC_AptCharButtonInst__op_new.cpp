extern void* gAllocator;
extern "C" void* poolAlloc(void*, unsigned int size);

void* AptCharButtonInst__op_new(unsigned int size) {
    return poolAlloc(gAllocator, size);
}
