// 0x80322A04 REffectsAttachment::New (48b)
typedef unsigned int uint;

struct EAHeap {
    void *Malloc(uint size, int flags);
};
EAHeap *MainHeap(void);

struct REffectsAttachment {
    char _pad[36];
    REffectsAttachment(void);
};

inline void *operator new(uint, void *p) { return p; }

REffectsAttachment *REffectsAttachment__New(void) {
    void *mem = MainHeap()->Malloc(36, 0);
    REffectsAttachment *p = new(mem) REffectsAttachment;
    return p;
}
