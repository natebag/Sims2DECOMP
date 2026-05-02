// 0x802C4DEC (112B) AptXmlAttributes::~AptXmlAttributes(void)
// Variant L (sibling of AptXmlNode): clear m_24 + vtable@+8 + AptNativeHash member dtor + AptValue dtor + AptValueGC_PoolManager Deallocate.

extern char vt_AptXmlAttributes[];
extern void* g_aptValueGCPool;

void AptNativeHash_dtor(void* obj, int flag);
void AptValue_dtor(void* obj, int flag);
void AptValueGC_PoolManager_DeallocateAptValueGC(void* mgr, void* p, unsigned int size);

struct AptNativeHash {
    char data[24];
};

struct AptXmlAttributes {
    char pad_0_7[8];
    void* m_vt_at_8;
    AptNativeHash m_hash;
    int m_field_24;
    void dtor(int flag);
};

void AptXmlAttributes::dtor(int flag) {
    m_field_24 = 0;
    m_vt_at_8 = vt_AptXmlAttributes;
    AptNativeHash_dtor(&m_hash, 2);
    AptValue_dtor(this, 0);
    if (flag & 1) {
        AptValueGC_PoolManager_DeallocateAptValueGC(g_aptValueGCPool, this, 40);
    }
}
