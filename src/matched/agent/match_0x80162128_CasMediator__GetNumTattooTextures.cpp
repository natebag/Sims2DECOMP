// 0x80162128 CasMediator::GetNumTattooTextures(eTattooTextureTypeS2C) const (40B)
// Null-check delegation
struct CasImpl;
struct CasMediator {
    char pad[20];
    CasImpl* m_impl;
};

extern int CasImpl__GetNumTattooTextures(CasImpl* self, int type);

int CasMediator__GetNumTattooTextures(CasMediator* self, int type) {
    CasImpl* impl = self->m_impl;
    if (impl == 0) return 0;
    return CasImpl__GetNumTattooTextures(impl, type);
}
