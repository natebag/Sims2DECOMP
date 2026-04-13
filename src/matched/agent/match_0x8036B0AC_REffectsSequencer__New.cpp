// 0x8036B0AC REffectsSequencer::New (48b)
typedef unsigned int uint;

struct EAHeap {
    void *Malloc(uint size, int flags);
};
EAHeap *MainHeap(void);

struct REffectsSequencer {
    char _pad[20];
    REffectsSequencer(void);
};

inline void *operator new(uint, void *p) { return p; }

REffectsSequencer *REffectsSequencer__New(void) {
    void *mem = MainHeap()->Malloc(20, 0);
    REffectsSequencer *p = new(mem) REffectsSequencer;
    return p;
}
