// PRAGMA_STUB: EIStaticModel::GetInstName(EInstance::InstType &)
// 0x8022DF1C EIStaticModel::GetInstName(EInstance::InstType&) (44B)
struct InstType {
    int kind;
};

struct EIStaticModel {
    char pad[288];
    int m_hasSub;
};

extern char kEIStaticModelNameWithSub[64];  // 0x8040ECCC — non-SDA
extern char kEIStaticModelNameNoSub[64];    // 0x8040EE40 — non-SDA

char* EIStaticModel__GetInstName(EIStaticModel* self, InstType& out) {
    out.kind = 3;
    if (self->m_hasSub != 0) return kEIStaticModelNameWithSub;
    return kEIStaticModelNameNoSub;
}
