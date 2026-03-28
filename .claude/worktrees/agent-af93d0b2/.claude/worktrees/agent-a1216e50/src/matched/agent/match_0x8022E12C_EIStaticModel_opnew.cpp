/* EIStaticModel::operator new(unsigned int) - 0x8022E12C (64 bytes) */

struct EAHeap {
    void *MallocAligned(unsigned int, unsigned int, unsigned int, int);
};

EAHeap *MainHeap();

struct EIStaticModel {
    void *operator new(unsigned int size);
};

void *EIStaticModel::operator new(unsigned int size)
{
    EAHeap *heap = MainHeap();
    return heap->MallocAligned(size, 16, 0, 0);
}
