// 0x801621F8 CasMediator::GetIndexes(eTattooTextureTypeS2C, unsigned char*, unsigned char*) (40B)
// Null-check delegation
struct CasImpl;
struct CasMediator {
    char pad[20];
    CasImpl* m_impl;
};

extern int CasImpl__GetIndexes_Tattoo(CasImpl* self, int type, unsigned char* a, unsigned char* b);

int CasMediator__GetIndexes_Tattoo(CasMediator* self, int type, unsigned char* a, unsigned char* b) {
    CasImpl* impl = self->m_impl;
    if (impl == 0) return 0;
    return CasImpl__GetIndexes_Tattoo(impl, type, a, b);
}
