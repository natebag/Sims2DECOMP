// 0x8030F4CC (92B) EREdithTreeSet::~EREdithTreeSet(void)
// Same SI deleting-dtor template as REffectsEmitter (operator delete = MainHeap()->Free).

class EAHeap {
public:
    void Free(void* p);
};

EAHeap* MainHeap();

class EResource {
public:
    virtual ~EResource();
};

class EREdithTreeSet : public EResource {
public:
    virtual ~EREdithTreeSet();
    void Deallocate();
    static void operator delete(void* p);
};

inline void EREdithTreeSet::operator delete(void* p) {
    MainHeap()->Free(p);
}

EREdithTreeSet::~EREdithTreeSet() {
    Deallocate();
}
