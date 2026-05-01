// 0x8031B83C (96B) ERQuickdata::~ERQuickdata(void)
// Custom-allocator variant of EResource SI deleting-dtor.

extern char g_quickdataHeap[];
void HeapStaticFree(char* heap, void* p);

class EResource {
public:
    virtual ~EResource();
};

class ERQuickdata : public EResource {
public:
    virtual ~ERQuickdata();
    void Deallocate();
    static void operator delete(void* p);
};

inline void ERQuickdata::operator delete(void* p) {
    HeapStaticFree(g_quickdataHeap, p);
}

ERQuickdata::~ERQuickdata() {
    Deallocate();
}
