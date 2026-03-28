/* CLoadingScreen::operator new(unsigned int) at 0x80057830 (64B) */

struct EAHeap {
    void *MallocAligned(unsigned int size, unsigned int align, unsigned int p3, int p4);
};

EAHeap *MainHeap(void);

void *CLoadingScreen_operator_new(unsigned int size) {
    EAHeap *heap = MainHeap();
    return heap->MallocAligned(size, 16, 0, 0);
}
