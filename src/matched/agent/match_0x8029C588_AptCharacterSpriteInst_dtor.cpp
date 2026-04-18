// 0x8029C588 (76B) AptCharacterSpriteInst::~AptCharacterSpriteInst(void)
extern void AptCharacterSpriteInstBase_dtor(void*, int);

class DOGMA_PoolManager {
public:
    void Deallocate(void* p, unsigned int size);
};
extern DOGMA_PoolManager* g_poolMgr;

struct AptCharacterSpriteInst {
    void dtor(int del);
};

void AptCharacterSpriteInst::dtor(int del) {
    AptCharacterSpriteInstBase_dtor(this, 0);
    if (del & 1) {
        g_poolMgr->Deallocate(this, 48);
    }
}
