// 0x8016215C CasMediator::GetIconTextureId(eBodyPartS2C, uint) const (40B)
// Null-check delegation
struct CasImpl;
struct CasMediator {
    char pad[20];
    CasImpl* m_impl;
};

extern int CasImpl__GetIconTextureId(CasImpl* self, int bodyPart, unsigned int idx);

int CasMediator__GetIconTextureId(CasMediator* self, int bodyPart, unsigned int idx) {
    CasImpl* impl = self->m_impl;
    if (impl == 0) return 0;
    return CasImpl__GetIconTextureId(impl, bodyPart, idx);
}
