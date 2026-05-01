// 0x8031C7A0 (104B) ERShader::~ERShader(void)
// Custom-allocator + sub-object Cleanup(2) at +0x3c.

extern char g_shaderHeap[];
void HeapStaticFree(char* heap, void* p);

class EResource {
public:
    virtual ~EResource();
};

class SubObj {
public:
    void Release();
};

class ERShader : public EResource {
public:
    char   pad[0x3c - 4];
    SubObj m_sub;

    virtual ~ERShader();
    void Deallocate();
    static void operator delete(void* p);
};

inline void ERShader::operator delete(void* p) {
    HeapStaticFree(g_shaderHeap, p);
}

ERShader::~ERShader() {
    Deallocate();
    m_sub.Release();
}
