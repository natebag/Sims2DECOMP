// PRAGMA_STUB: ERDataset::New(void)
// 0x80369780 ERDataset::New (48b)
typedef unsigned int uint;

struct EAHeap {
    void *Malloc(uint size, int flags);
};
EAHeap *MainHeap(void);

struct ERDataset {
    char _pad[36];
    ERDataset(void);
};

inline void *operator new(uint, void *p) { return p; }

ERDataset *ERDataset__New(void) {
    void *mem = MainHeap()->Malloc(36, 0);
    ERDataset *p = new(mem) ERDataset;
    return p;
}
