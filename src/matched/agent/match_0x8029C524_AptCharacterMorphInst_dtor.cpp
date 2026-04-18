// 0x8029C524 (100B) AptCharacterMorphInst::~AptCharacterMorphInst(void)
extern int AptCharacterMorphInst_vtbl[];

struct AptNativeHash;
extern void AptNativeHash_dtor(AptNativeHash*, int);

class DOGMA_PoolManager {
public:
    void Deallocate(void* p, unsigned int size);
};
extern DOGMA_PoolManager* g_poolMgr;

struct AptCharacterMorphInst {
    char pad[0xc];
    AptNativeHash* m_hash;
    int pad2;
    int* m_vtable;
    void dtor(int del);
};

void AptCharacterMorphInst::dtor(int del) {
    m_vtable = AptCharacterMorphInst_vtbl;
    if (m_hash) {
        AptNativeHash_dtor(m_hash, 3);
    }
    if (del & 1) {
        g_poolMgr->Deallocate(this, 28);
    }
}
