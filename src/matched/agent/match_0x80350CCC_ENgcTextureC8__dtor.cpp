// 0x80350CCC (88B) ENgcTextureC8::~ENgcTextureC8(void)
// Twin of ENgcTextureC4 — vtable-at-+0x24 SI deleting-dtor.

extern char vt_ENgcTextureC8[];
extern char g_textureHeap[];
void HeapStaticFree(char* heap, void* p);

class ENgcTextureBase {
public:
    void* m_base_vt;
    ~ENgcTextureBase();
};

class ENgcTextureC8 : public ENgcTextureBase {
public:
    char  pad[0x24 - 4];
    void* m_vt_at_24;

    ~ENgcTextureC8();
    static void operator delete(void* p);
};

inline void ENgcTextureC8::operator delete(void* p) {
    HeapStaticFree(g_textureHeap, p);
}

ENgcTextureC8::~ENgcTextureC8() {
    m_vt_at_24 = vt_ENgcTextureC8;
}
