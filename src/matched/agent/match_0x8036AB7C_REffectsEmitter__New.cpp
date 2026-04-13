// 0x8036AB7C REffectsEmitter::New (48b)
typedef unsigned int uint;

struct EAHeap {
    void *Malloc(uint size, int flags);
};
EAHeap *MainHeap(void);

struct REffectsEmitter {
    char _pad[36];
    REffectsEmitter(void);
};

inline void *operator new(uint, void *p) { return p; }

REffectsEmitter *REffectsEmitter__New(void) {
    void *mem = MainHeap()->Malloc(36, 0);
    REffectsEmitter *p = new(mem) REffectsEmitter;
    return p;
}
