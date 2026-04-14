// 0x80162190 CasMediator::GetIconTattooTextureId(eTattooTextureTypeS2C, uint) const (40B)
// Null-check delegation
struct CasImpl;
struct CasMediator {
    char pad[20];
    CasImpl* m_impl;
};

extern int CasImpl__GetIconTattooTextureId(CasImpl* self, int type, unsigned int idx);

int CasMediator__GetIconTattooTextureId(CasMediator* self, int type, unsigned int idx) {
    CasImpl* impl = self->m_impl;
    if (impl == 0) return 0;
    return CasImpl__GetIconTattooTextureId(impl, type, idx);
}
