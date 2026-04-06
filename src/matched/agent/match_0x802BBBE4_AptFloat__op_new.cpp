extern void* gAllocator;
extern "C" void* poolAlloc(void*, unsigned int size);

void* AptFloat__op_new(unsigned int size) {
    return poolAlloc(gAllocator, size);
}
