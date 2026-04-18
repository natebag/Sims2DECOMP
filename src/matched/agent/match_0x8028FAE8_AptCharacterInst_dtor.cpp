// 0x8028FAE8 (92B) AptCharacterInst::~AptCharacterInst(void) — template twin of 0x8029C5F4/0x802C4C68
extern int AptCharacterInst_vtbl[];
struct AptNativeHash;
extern void _delete(void*);
extern void AptNativeHash_dtor(AptNativeHash*, int);

struct AptCharacterInst {
    char pad[0xc];
    AptNativeHash* m_hash;
    int pad2;
    int* m_vtable;
    void dtor(int del);
};

void AptCharacterInst::dtor(int del) {
    m_vtable = AptCharacterInst_vtbl;
    if (m_hash) {
        AptNativeHash_dtor(m_hash, 3);
    }
    if (del & 1) {
        _delete(this);
    }
}
