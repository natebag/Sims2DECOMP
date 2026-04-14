// 0x801621C4 CasMediator::GetIndexes(eBodyPartS2C, unsigned char*, unsigned char*) (40B)
// Null-check delegation
struct CasImpl;
struct CasMediator {
    char pad[20];
    CasImpl* m_impl;
};

extern int CasImpl__GetIndexes_BodyPart(CasImpl* self, int bodyPart, unsigned char* a, unsigned char* b);

int CasMediator__GetIndexes_BodyPart(CasMediator* self, int bodyPart, unsigned char* a, unsigned char* b) {
    CasImpl* impl = self->m_impl;
    if (impl == 0) return 0;
    return CasImpl__GetIndexes_BodyPart(impl, bodyPart, a, b);
}
