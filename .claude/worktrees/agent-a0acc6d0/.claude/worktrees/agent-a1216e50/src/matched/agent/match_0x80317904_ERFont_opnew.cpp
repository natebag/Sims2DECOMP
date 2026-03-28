/* ERFont::operator new(unsigned int) - 0x80317904 (64 bytes) */

struct EAHeap {
    void *MallocAligned(unsigned int, unsigned int, unsigned int, int);
};

EAHeap *MainHeap();

struct ERFont {
    void *operator new(unsigned int size);
};

void *ERFont::operator new(unsigned int size)
{
    EAHeap *heap = MainHeap();
    return heap->MallocAligned(size, 16, 0, 0);
}
