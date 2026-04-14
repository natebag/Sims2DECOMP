// 0x8031B2BC ERModel::GetTypeKey (12B) const
extern int g_ERModel_TypeKey[3];
struct ERModel_GTK { int GetTypeKey() const; };
int ERModel_GTK::GetTypeKey() const { return g_ERModel_TypeKey[0]; }
