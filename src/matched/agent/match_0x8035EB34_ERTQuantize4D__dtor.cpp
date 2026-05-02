// 0x8035EB34 (80B) ERTQuantize4D::~ERTQuantize4D(void)
// Twin of ERTQuantize — standard SI deleting-dtor, MainHeap.

class EAHeap {
public:
    void Free(void* p);
};

EAHeap* MainHeap();

class ERTQuantize4D {
public:
    virtual ~ERTQuantize4D();
    void Deallocate();
    static void operator delete(void* p);
};

inline void ERTQuantize4D::operator delete(void* p) {
    MainHeap()->Free(p);
}

ERTQuantize4D::~ERTQuantize4D() {
    Deallocate();
}
