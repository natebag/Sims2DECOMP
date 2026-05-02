// 0x802CE71C (80B) ERTQuantize::~ERTQuantize(void)
// Standard SI deleting-dtor (no parent), MainHeap()->Free.

class EAHeap {
public:
    void Free(void* p);
};

EAHeap* MainHeap();

class ERTQuantize {
public:
    virtual ~ERTQuantize();
    void Deallocate();
    static void operator delete(void* p);
};

inline void ERTQuantize::operator delete(void* p) {
    MainHeap()->Free(p);
}

ERTQuantize::~ERTQuantize() {
    Deallocate();
}
