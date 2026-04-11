// FLAGS: -fno-elide-constructors
/* EResource::EResource(void) at 0x80311DC8 (48 bytes) */

extern char EResource_typeInfo[];

struct EResource {
    void* m_pTypeInfo;      // 0x00 — manually-stored type descriptor
    void* m_pManager;       // 0x04
    unsigned int m_resId;   // 0x08
    short m_refCount;       // 0x0C
    short m_flags;          // 0x0E
    unsigned int m_resSize; // 0x10
    EResource();
};

EResource::EResource() {
    m_refCount = 1;
    m_pTypeInfo = EResource_typeInfo;
    m_flags = 0;
    m_resSize = 128;
    m_pManager = 0;
}
