extern int EResource_vtable[];

struct EResourceManager;

struct EResource {
    int* m_vtable;
    EResourceManager* m_pManager;
    int m_resId;
    short m_numRefs;
    short m_flags;
    int m_size;

    EResource();
};

EResource::EResource()
{
    int* vt = EResource_vtable;
    EResourceManager* zero = 0;
    m_numRefs = 1;
    m_vtable = vt;
    m_flags = (short)(int)zero;
    m_size = 0x80;
    m_pManager = zero;
}
