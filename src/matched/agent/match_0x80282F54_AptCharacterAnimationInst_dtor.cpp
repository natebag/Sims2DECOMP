// 0x80282F54 (124B) AptCharacterAnimationInst::~AptCharacterAnimationInst(void)
extern int AptCharacterAnimationInst_vtbl[];

struct AptFile;
extern int AptSharedPtrDecRef(AptFile*);
extern void AptSharedPtrDelete(AptFile*);
extern void AptCharacterSpriteInstBase_dtor(void*, int);

class DOGMA_PoolManager {
public:
    void Deallocate(void* p, unsigned int size);
};
extern DOGMA_PoolManager* g_poolMgr;

struct AptCharacterAnimationInst {
    char pad[0x14];
    int* m_vtable;
    char pad2[0x1c];
    AptFile* m_file;
    void dtor(int del);
};

void AptCharacterAnimationInst::dtor(int del) {
    m_vtable = AptCharacterAnimationInst_vtbl;
    if (m_file != 0) {
        if (AptSharedPtrDecRef(m_file) == 0) {
            AptSharedPtrDelete(m_file);
        }
    }
    AptCharacterSpriteInstBase_dtor(this, 0);
    if (del & 1) {
        g_poolMgr->Deallocate(this, 56);
    }
}
