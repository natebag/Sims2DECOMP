// 0x80285DEC AptArray::DestroyGCPointers(void) (200B) — clean
//
// Tears down the array's GC references: runs the base teardown, GC-releases every
// live element (clearing each slot), frees the backing store, and zeroes the
// data pointer, capacity, and count.

struct AptValueData { unsigned int w0; unsigned int w4; };
struct AptValue : AptValueData {
    virtual void GCRegister(char* file, char* func, int line);   // vtable slot 1 (@8/@12)
    virtual void GCRelease(char* file, char* func, int line);    // vtable slot 2 (@16/@20)
};

extern char gDestroyDesc1[];   // absolute @0x80403F0C
extern char gDestroyDesc2[];   // absolute @0x80403EB8

struct AptValuePool { void Deallocate(void* p, unsigned int size); };  // @0x802B598C
extern AptValuePool* g_aptValuePool;   // SDA -0x59ec

struct AptArray {
    char       pad[0x24];   // 0x00 .. 0x23
    AptValue** m_data;      // 0x24
    int        m_capacity;  // 0x28
    int        m_count;     // 0x2C
    void destroyBase();                 // base DestroyGCPointers @0x802B5E74
    void DestroyGCPointers();
};

void AptArray::DestroyGCPointers() {
    destroyBase();
    for (int i = 0; i < m_count; i++) {
        AptValue* elem = m_data[i];
        if (elem != 0) {
            elem->GCRelease(gDestroyDesc1, gDestroyDesc2, 138);
            m_data[i] = 0;
        }
    }
    if (m_data != 0) {
        g_aptValuePool->Deallocate(m_data, m_capacity * 4);
    }
    m_data = 0;
    m_count = 0;
    m_capacity = 0;
}
