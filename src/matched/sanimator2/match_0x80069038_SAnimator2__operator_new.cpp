// 0x80069038 SAnimator2::operator new(unsigned int) (84B)
// Pattern: heap-backed operator new — MainHeap + MallocAligned + memset
extern "C" void* memset(void* p, int c, unsigned int n);

class EAHeap {
public:
    void* MallocAligned(unsigned int size, unsigned int align, unsigned int pad1, int pad2);
};

extern EAHeap* MainHeap();

class SAnimator2 {
public:
    static void* operator new(unsigned int size);
};

void* SAnimator2::operator new(unsigned int size) {
    EAHeap* h = MainHeap();
    void* p = h->MallocAligned(size, 16, 0, 0);
    memset(p, 0, size);
    return p;
}
