// 0x80313F88 (104B) ERFont::~ERFont(void)
// Standard-heap variant + sub-object Cleanup(2) at +0x14.

class EAHeap {
public:
    void Free(void* p);
};

EAHeap* MainHeap();

class EResource {
public:
    virtual ~EResource();
};

class SubObj {
public:
    void Cleanup(int);
};

class ERFont : public EResource {
public:
    char   pad[0x14 - 4];
    SubObj m_sub;

    virtual ~ERFont();
    void Deallocate();
    static void operator delete(void* p);
};

inline void ERFont::operator delete(void* p) {
    MainHeap()->Free(p);
}

ERFont::~ERFont() {
    Deallocate();
    m_sub.Cleanup(2);
}
