// 0x80369A00 (104B) ERSoundEvent::~ERSoundEvent(void)
// Custom-allocator + sub-object Cleanup(2) at +0x24.

extern char g_soundEventHeap[];
void HeapStaticFree(char* heap, void* p);

class EResource {
public:
    virtual ~EResource();
};

class SubObj {
public:
    void Cleanup(int);
};

class ERSoundEvent : public EResource {
public:
    char   pad[0x24 - 4];
    SubObj m_sub;

    virtual ~ERSoundEvent();
    static void operator delete(void* p);
};

inline void ERSoundEvent::operator delete(void* p) {
    HeapStaticFree(g_soundEventHeap, p);
}

ERSoundEvent::~ERSoundEvent() {
    m_sub.Cleanup(2);
}
