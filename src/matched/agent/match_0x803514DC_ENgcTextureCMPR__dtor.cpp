// 0x803514DC (88B) ENgcTextureCMPR::~ENgcTextureCMPR(void)
// Twin of ENgcTextureC4 — vtable-at-+0x24 SI deleting-dtor.

extern char vt_ENgcTextureCMPR[];
extern char g_textureHeap[];
void HeapStaticFree(char* heap, void* p);

class ENgcTextureBase {
public:
    void* m_base_vt;
    ~ENgcTextureBase();
};

class ENgcTextureCMPR : public ENgcTextureBase {
public:
    char  pad[0x24 - 4];
    void* m_vt_at_24;

    ~ENgcTextureCMPR();
    static void operator delete(void* p);
};

inline void ENgcTextureCMPR::operator delete(void* p) {
    HeapStaticFree(g_textureHeap, p);
}

ENgcTextureCMPR::~ENgcTextureCMPR() {
    m_vt_at_24 = vt_ENgcTextureCMPR;
}
