/* EIStaticSubModel::operator new(unsigned int) - 0x8022F894 (64 bytes) */

struct EAHeap {
    void *MallocAligned(unsigned int, unsigned int, unsigned int, int);
};

EAHeap *MainHeap();

struct EIStaticSubModel {
    void *operator new(unsigned int size);
};

void *EIStaticSubModel::operator new(unsigned int size)
{
    EAHeap *heap = MainHeap();
    return heap->MallocAligned(size, 16, 0, 0);
}
