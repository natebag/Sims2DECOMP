/* ERTQuantize::operator new(unsigned int) - 0x802CFD2C (64 bytes) */

struct EAHeap {
    void *MallocAligned(unsigned int, unsigned int, unsigned int, int);
};

EAHeap *MainHeap();

struct ERTQuantize {
    void *operator new(unsigned int size);
};

void *ERTQuantize::operator new(unsigned int size)
{
    EAHeap *heap = MainHeap();
    return heap->MallocAligned(size, 16, 0, 0);
}
