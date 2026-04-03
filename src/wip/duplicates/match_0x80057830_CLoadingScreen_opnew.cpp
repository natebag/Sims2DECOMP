/* CLoadingScreen::operator new(unsigned int) - 0x80057830 (64 bytes) */

struct EAHeap {
    void *MallocAligned(unsigned int, unsigned int, unsigned int, int);
};

EAHeap *MainHeap();

struct CLoadingScreen {
    void *operator new(unsigned int size);
};

void *CLoadingScreen::operator new(unsigned int size)
{
    EAHeap *heap = MainHeap();
    return heap->MallocAligned(size, 16, 0, 0);
}
