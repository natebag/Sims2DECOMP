/* EWindow::operator new(unsigned int) - 0x8030082C (64 bytes) */

struct EAHeap {
    void *MallocAligned(unsigned int, unsigned int, unsigned int, int);
};

EAHeap *MainHeap();

struct EWindow {
    void *operator new(unsigned int size);
};

void *EWindow::operator new(unsigned int size)
{
    EAHeap *heap = MainHeap();
    return heap->MallocAligned(size, 16, 0, 0);
}
