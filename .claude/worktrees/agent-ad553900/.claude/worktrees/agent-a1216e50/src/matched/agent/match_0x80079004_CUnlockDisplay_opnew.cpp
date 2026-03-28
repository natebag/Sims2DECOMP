/* CUnlockDisplay::operator new(unsigned int) - 0x80079004 (64 bytes) */

struct EAHeap {
    void *MallocAligned(unsigned int, unsigned int, unsigned int, int);
};

EAHeap *MainHeap();

struct CUnlockDisplay {
    void *operator new(unsigned int size);
};

void *CUnlockDisplay::operator new(unsigned int size)
{
    EAHeap *heap = MainHeap();
    return heap->MallocAligned(size, 16, 0, 0);
}
