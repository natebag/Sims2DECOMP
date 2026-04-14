// 0x80053F70 ISimsWallObjectModel::GetTypeKey (12B) const
extern int g_ISimsWallObjectModel_TypeKey[3];
struct ISimsWallObjectModel_GTK { int GetTypeKey() const; };
int ISimsWallObjectModel_GTK::GetTypeKey() const { return g_ISimsWallObjectModel_TypeKey[0]; }
