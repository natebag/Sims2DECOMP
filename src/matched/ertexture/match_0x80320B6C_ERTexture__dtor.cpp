// 0x80320B6C (96B) ERTexture::~ERTexture(void)
// Custom-allocator variant of EResource SI deleting-dtor.

extern char g_textureHeap[];
void HeapStaticFree(char* heap, void* p);

class EResource {
public:
    virtual ~EResource();
};

class ERTexture : public EResource {
public:
    virtual ~ERTexture();
    void Deallocate();
    static void operator delete(void* p);
};

inline void ERTexture::operator delete(void* p) {
    HeapStaticFree(g_textureHeap, p);
}

ERTexture::~ERTexture() {
    Deallocate();
}
