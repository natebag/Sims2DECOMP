// 0x802BA438 (116B) AptXmlNode::~AptXmlNode(void)
// Variant L: clear m_24/m_28 + vtable@+8 + AptNativeHash member dtor + AptValue dtor + AptValueGC_PoolManager Deallocate.

extern char vt_AptXmlNode[];
extern void* g_aptValueGCPool;

void AptNativeHash_dtor(void* obj, int flag);
void AptValue_dtor(void* obj, int flag);
void AptValueGC_PoolManager_DeallocateAptValueGC(void* mgr, void* p, unsigned int size);

struct AptNativeHash {
    char data[24];
};

struct AptXmlNode {
    char pad_0_7[8];
    void* m_vt_at_8;
    AptNativeHash m_hash;
    int m_field_24;
    int m_field_28;
    void dtor(int flag);
};

void AptXmlNode::dtor(int flag) {
    m_field_24 = 0;
    m_field_28 = 0;
    m_vt_at_8 = vt_AptXmlNode;
    AptNativeHash_dtor(&m_hash, 2);
    AptValue_dtor(this, 0);
    if (flag & 1) {
        AptValueGC_PoolManager_DeallocateAptValueGC(g_aptValueGCPool, this, 44);
    }
}
