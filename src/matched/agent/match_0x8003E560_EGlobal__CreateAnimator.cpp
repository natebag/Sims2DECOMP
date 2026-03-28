/* EGlobal::CreateAnimator(void) at 0x8003E560 (84B) */

typedef unsigned int uint;

struct EAHeap {
    void *MallocAligned(uint size, uint align, uint flags, int extra);
};

EAHeap *MainHeap(void);
void *memset(void *, int, uint);

struct SAnimator2 {
    SAnimator2(void);
};

inline void *operator new(uint, void *p) { return p; }

SAnimator2 *EGlobal_CreateAnimator(void) {
    EAHeap *heap = MainHeap();
    void *p = heap->MallocAligned(1648, 16, 0, 0);
    memset(p, 0, 1648);
    SAnimator2 *anim = new(p) SAnimator2;
    return anim;
}
