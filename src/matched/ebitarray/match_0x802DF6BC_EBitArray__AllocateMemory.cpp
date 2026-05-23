// EBitArray::AllocateMemory(unsigned long) - 0x802DF6BC (56B)

struct EAHeap {
    void* Malloc(unsigned int size, int align);
};

EAHeap* MainHeap();

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    void* AllocateMemory(unsigned long size);
};

void* EBitArray::AllocateMemory(unsigned long size) {
    return MainHeap()->Malloc(size, 0);
}
