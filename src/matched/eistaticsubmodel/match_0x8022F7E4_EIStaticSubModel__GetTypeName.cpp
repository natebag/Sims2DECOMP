// 0x8022F7E4 EIStaticSubModel::GetTypeName (12B) const
extern char* g_EIStaticSubModel_TypeName[3];
struct EIStaticSubModel_GTN { const char* GetTypeName() const; };
const char* EIStaticSubModel_GTN::GetTypeName() const { return g_EIStaticSubModel_TypeName[0]; }
