/* ESim::New(void) at 0x80035018 (84B) */

typedef unsigned int uint;

struct EAHeap {
    void *MallocAligned(uint size, uint align, uint flags, int extra);
};

EAHeap *MainHeap(void);
void *memset(void *, int, uint);

struct ESim {
    ESim(void);
    static ESim *New(void);
};

inline void *operator new(uint, void *p) { return p; }

ESim *ESim::New(void) {
    EAHeap *heap = MainHeap();
    void *p = heap->MallocAligned(1608, 16, 0, 0);
    memset(p, 0, 1608);
    ESim *sim = new(p) ESim;
    return sim;
}
