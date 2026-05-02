// 0x803515E4 (88B) ENgcTextureRGB5A3::~ENgcTextureRGB5A3(void)
// Twin of ENgcTextureC4 — vtable-at-+0x24 SI deleting-dtor.

extern char vt_ENgcTextureRGB5A3[];
extern char g_textureHeap[];
void HeapStaticFree(char* heap, void* p);

class ENgcTextureBase {
public:
    void* m_base_vt;
    ~ENgcTextureBase();
};

class ENgcTextureRGB5A3 : public ENgcTextureBase {
public:
    char  pad[0x24 - 4];
    void* m_vt_at_24;

    ~ENgcTextureRGB5A3();
    static void operator delete(void* p);
};

inline void ENgcTextureRGB5A3::operator delete(void* p) {
    HeapStaticFree(g_textureHeap, p);
}

ENgcTextureRGB5A3::~ENgcTextureRGB5A3() {
    m_vt_at_24 = vt_ENgcTextureRGB5A3;
}
