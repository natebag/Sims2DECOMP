// 0x80350664 (88B) ENgcTextureC4::~ENgcTextureC4(void)
// Vtable-at-+0x24 SI deleting-dtor: extern char vt[] recipe + explicit base dtor chain.

extern char vt_ENgcTextureC4[];
extern char g_textureHeap[];
void HeapStaticFree(char* heap, void* p);

class ENgcTextureBase {
public:
    void* m_base_vt;
    ~ENgcTextureBase();
};

class ENgcTextureC4 : public ENgcTextureBase {
public:
    char  pad[0x24 - 4];
    void* m_vt_at_24;

    ~ENgcTextureC4();
    static void operator delete(void* p);
};

inline void ENgcTextureC4::operator delete(void* p) {
    HeapStaticFree(g_textureHeap, p);
}

ENgcTextureC4::~ENgcTextureC4() {
    m_vt_at_24 = vt_ENgcTextureC4;
}
