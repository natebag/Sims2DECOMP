// 0x8036B34C (96B) RParticle::~RParticle(void)
// Custom-allocator variant of EResource SI deleting-dtor.

extern char g_particleHeap[];
void HeapStaticFree(char* heap, void* p);

class EResource {
public:
    virtual ~EResource();
};

class RParticle : public EResource {
public:
    virtual ~RParticle();
    void Deallocate();
    static void operator delete(void* p);
};

inline void RParticle::operator delete(void* p) {
    HeapStaticFree(g_particleHeap, p);
}

RParticle::~RParticle() {
    Deallocate();
}
