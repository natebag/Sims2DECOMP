// 0x8022E088 EIStaticModel::GetTypeKey (12B) const
extern int g_EIStaticModel_TypeKey[3];
struct EIStaticModel_GTK { int GetTypeKey() const; };
int EIStaticModel_GTK::GetTypeKey() const { return g_EIStaticModel_TypeKey[0]; }
