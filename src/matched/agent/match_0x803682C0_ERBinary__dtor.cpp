// 0x803682C0 (92B) ERBinary::~ERBinary(void)
// Same SI deleting-dtor template as REffectsEmitter.

class EAHeap {
public:
    void Free(void* p);
};

EAHeap* MainHeap();

class EResource {
public:
    virtual ~EResource();
};

class ERBinary : public EResource {
public:
    virtual ~ERBinary();
    void Deallocate();
    static void operator delete(void* p);
};

inline void ERBinary::operator delete(void* p) {
    MainHeap()->Free(p);
}

ERBinary::~ERBinary() {
    Deallocate();
}
