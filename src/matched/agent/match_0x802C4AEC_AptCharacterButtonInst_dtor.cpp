extern int AptCharacterButtonInst_vtbl[];

struct AptDisplayList;
extern void AptDisplayList_dtor(AptDisplayList*, int);

struct AptNativeHash;
extern void AptNativeHash_dtor(AptNativeHash*, int);

class DOGMA_PoolManager {
public:
    void Deallocate(void* p, unsigned int size);
};
extern DOGMA_PoolManager* g_poolMgr;

struct AptCharacterButtonInst {
    char pad[0xc];
    AptNativeHash* m_hash;
    int pad2;
    int* m_vtable;
    int pad3;
    AptDisplayList* m_displayList_ptr;  // offset 0x1C = &member
    void dtor(int del);
};

void AptCharacterButtonInst::dtor(int del) {
    AptDisplayList_dtor((AptDisplayList*)((char*)this + 0x1C), 2);
    m_vtable = AptCharacterButtonInst_vtbl;
    if (m_hash) {
        AptNativeHash_dtor(m_hash, 3);
    }
    if (del & 1) {
        g_poolMgr->Deallocate(this, 32);
    }
}
