// 0x801620F4 CasMediator::GetNumBodyModels(eBodyPartS2C) const (40B)
// Null-check delegation: if m_impl == 0 return 0, else impl->GetNumBodyModels(arg)
struct CasImpl;
struct CasMediator {
    char pad[20];
    CasImpl* m_impl;
};

extern int CasImpl__GetNumBodyModels(CasImpl* self, int bodyPart);

int CasMediator__GetNumBodyModels(CasMediator* self, int bodyPart) {
    CasImpl* impl = self->m_impl;
    if (impl == 0) return 0;
    return CasImpl__GetNumBodyModels(impl, bodyPart);
}
