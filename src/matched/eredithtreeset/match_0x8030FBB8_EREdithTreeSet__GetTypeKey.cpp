// 0x8030FBB8 EREdithTreeSet::GetTypeKey (12B) const
extern int g_EREdithTreeSet_TypeKey[3];
struct EREdithTreeSet_GTK { int GetTypeKey() const; };
int EREdithTreeSet_GTK::GetTypeKey() const { return g_EREdithTreeSet_TypeKey[0]; }
