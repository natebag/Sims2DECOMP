// 0x80351748 (88B) ENgcTextureRGBA8::~ENgcTextureRGBA8(void)
// Twin of ENgcTextureC4 — vtable-at-+0x24 SI deleting-dtor.

extern char vt_ENgcTextureRGBA8[];
extern char g_textureHeap[];
void HeapStaticFree(char* heap, void* p);

class ENgcTextureBase {
public:
    void* m_base_vt;
    ~ENgcTextureBase();
};

class ENgcTextureRGBA8 : public ENgcTextureBase {
public:
    char  pad[0x24 - 4];
    void* m_vt_at_24;

    ~ENgcTextureRGBA8();
    static void operator delete(void* p);
};

inline void ENgcTextureRGBA8::operator delete(void* p) {
    HeapStaticFree(g_textureHeap, p);
}

ENgcTextureRGBA8::~ENgcTextureRGBA8() {
    m_vt_at_24 = vt_ENgcTextureRGBA8;
}
