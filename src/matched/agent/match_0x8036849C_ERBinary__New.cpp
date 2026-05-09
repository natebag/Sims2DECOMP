// PRAGMA_STUB: ERBinary::New(void)
// 0x8036849C ERBinary::New (48b)
typedef unsigned int uint;

struct EAHeap {
    void *Malloc(uint size, int flags);
};
EAHeap *MainHeap(void);

struct ERBinary {
    char _pad[28];
    ERBinary(void);
};

inline void *operator new(uint, void *p) { return p; }

ERBinary *ERBinary__New(void) {
    void *mem = MainHeap()->Malloc(28, 0);
    ERBinary *p = new(mem) ERBinary;
    return p;
}
