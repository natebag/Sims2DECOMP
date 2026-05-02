// 0x80281D88 (88B) AptLookup::~AptLookup(void)
// Variant L (sibling of AptRegister): vtable@+8, parent ~AptValue(flag=0), custom delete via DOGMA_PoolManager.

extern char vt_AptLookup[];
extern void* g_dogmaPool;

void AptValue_dtor(void* obj, int flag);
void DOGMA_PoolManager_Deallocate(void* mgr, void* p, unsigned int size);

struct AptLookup {
    char pad_0_7[8];
    void* m_vt_at_8;
    void dtor(int flag);
};

void AptLookup::dtor(int flag) {
    m_vt_at_8 = vt_AptLookup;
    AptValue_dtor(this, 0);
    if (flag & 1) {
        DOGMA_PoolManager_Deallocate(g_dogmaPool, this, 16);
    }
}
