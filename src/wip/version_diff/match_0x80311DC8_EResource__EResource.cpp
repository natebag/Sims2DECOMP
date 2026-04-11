/* EResource::EResource(void) at 0x80311DC8 (48B) */

typedef short s16;
typedef unsigned int u32;

struct EResource {
    void*   m_pManager;  // 0x04 (vtable at 0x00 from virtual)
    u32     m_resId;     // 0x08
    s16     m_refCount;  // 0x0C
    s16     m_flags;     // 0x0E
    u32     m_resSize;   // 0x10
    EResource(void);
    virtual ~EResource(void);
};

EResource::EResource(void) {
    m_refCount = 1;
    m_pManager = 0;
    m_flags = 0;
    m_resSize = 128;
}
