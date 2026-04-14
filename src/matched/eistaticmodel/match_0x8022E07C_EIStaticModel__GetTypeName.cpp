// 0x8022E07C EIStaticModel::GetTypeName (12B) const
extern char* g_EIStaticModel_TypeName[3];
struct EIStaticModel_GTN { const char* GetTypeName() const; };
const char* EIStaticModel_GTN::GetTypeName() const { return g_EIStaticModel_TypeName[0]; }
