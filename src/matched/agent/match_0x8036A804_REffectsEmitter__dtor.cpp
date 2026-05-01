// 0x8036A804 (92B) REffectsEmitter::~REffectsEmitter(void)
// Standard SI deleting dtor: vtable @ +0, body calls Deallocate, base dtor chain,
// if in-charge flag set then operator delete via MainHeap()->Free.

class EAHeap {
public:
    void Free(void* p);
};

EAHeap* MainHeap();

class EResource {
public:
    virtual ~EResource();
};

class REffectsEmitter : public EResource {
public:
    virtual ~REffectsEmitter();
    void Deallocate();
    static void operator delete(void* p);
};

inline void REffectsEmitter::operator delete(void* p) {
    MainHeap()->Free(p);
}

REffectsEmitter::~REffectsEmitter() {
    Deallocate();
}
