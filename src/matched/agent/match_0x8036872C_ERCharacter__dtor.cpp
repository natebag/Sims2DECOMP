// 0x8036872C (104B) ERCharacter::~ERCharacter(void)
// Custom-allocator + sub-object Cleanup(2) at +0x14.

extern char g_characterHeap[];
void HeapStaticFree(char* heap, void* p);

class EResource {
public:
    virtual ~EResource();
};

class SubObj {
public:
    void Cleanup(int);
};

class ERCharacter : public EResource {
public:
    char   pad[0x14 - 4];
    SubObj m_sub;

    virtual ~ERCharacter();
    static void operator delete(void* p);
};

inline void ERCharacter::operator delete(void* p) {
    HeapStaticFree(g_characterHeap, p);
}

ERCharacter::~ERCharacter() {
    m_sub.Cleanup(2);
}
