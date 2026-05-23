// 0x8036AEAC (92B) REffectsSequencer::~REffectsSequencer(void)
// Twin of REffectsEmitter dtor — same SI deleting dtor pattern.

class EAHeap {
public:
    void Free(void* p);
};

EAHeap* MainHeap();

class EResource {
public:
    virtual ~EResource();
};

class REffectsSequencer : public EResource {
public:
    virtual ~REffectsSequencer();
    void Deallocate();
    static void operator delete(void* p);
};

inline void REffectsSequencer::operator delete(void* p) {
    MainHeap()->Free(p);
}

REffectsSequencer::~REffectsSequencer() {
    Deallocate();
}
