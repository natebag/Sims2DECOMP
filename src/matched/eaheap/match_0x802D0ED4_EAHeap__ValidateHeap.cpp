/* EAHeap::ValidateHeap(EA::Allocator::GeneralAllocator::HeapValidationLevel) - 0x802D0ED4 (80 bytes) */

struct EAHeap {
    unsigned int GetSize(void);
    void Validate1(void);
    int Validate2(void *arg);
    int ValidateHeap(void *arg);
};

int EAHeap::ValidateHeap(void *arg) {
    if (GetSize() <= 1024)
        return 1;
    Validate1();
    return Validate2(arg);
}
