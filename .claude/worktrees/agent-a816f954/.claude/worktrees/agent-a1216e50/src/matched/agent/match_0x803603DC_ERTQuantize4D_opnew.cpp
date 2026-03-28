/* ERTQuantize4D::operator new(unsigned int) - 0x803603DC (64 bytes) */

struct EAHeap {
    void *MallocAligned(unsigned int, unsigned int, unsigned int, int);
};

EAHeap *MainHeap();

struct ERTQuantize4D {
    void *operator new(unsigned int size);
};

void *ERTQuantize4D::operator new(unsigned int size)
{
    EAHeap *heap = MainHeap();
    return heap->MallocAligned(size, 16, 0, 0);
}
