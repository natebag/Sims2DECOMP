// 0x800B8DF0 (92B) cSoundCacheItem::~cSoundCacheItem(void)
// Variant L: SI deleting-dtor — conditional EResourceManager::DelRef + MainHeap delete.

extern void* g_eResourceMgr;

class EAHeap {
public:
    void Free(void* p);
};
EAHeap* MainHeap();

void EResourceManager_DelRef(void* mgr, unsigned int handle, int mode);

struct cSoundCacheItem {
    unsigned int m_field_0;
    char pad_4_f[12];
    int m_field_10;
    void dtor(int flag);
};

void cSoundCacheItem::dtor(int flag) {
    if (m_field_10 != 0) {
        EResourceManager_DelRef(g_eResourceMgr, m_field_0, 1);
    }
    if (flag & 1) {
        MainHeap()->Free(this);
    }
}
