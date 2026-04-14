// 0x8022F7F0 EIStaticSubModel::GetTypeKey (12B) const
extern int g_EIStaticSubModel_TypeKey[3];
struct EIStaticSubModel_GTK { int GetTypeKey() const; };
int EIStaticSubModel_GTK::GetTypeKey() const { return g_EIStaticSubModel_TypeKey[0]; }
