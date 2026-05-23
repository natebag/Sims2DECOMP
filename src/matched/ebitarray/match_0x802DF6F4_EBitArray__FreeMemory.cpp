// EBitArray::FreeMemory(void*) - 0x802DF6F4 (56B)

class EAHeap {
public:
    void Free(void* p);
};
EAHeap* MainHeap();

struct EBitArray {
    void FreeMemory(void* ptr);
};

void EBitArray::FreeMemory(void* ptr) {
    if (ptr) {
        MainHeap()->Free(ptr);
    }
}
