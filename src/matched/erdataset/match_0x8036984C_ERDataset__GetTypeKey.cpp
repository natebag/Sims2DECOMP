// 0x8036984C ERDataset::GetTypeKey (12B) const
extern int g_ERDataset_TypeKey[3];
struct ERDataset_GTK { int GetTypeKey() const; };
int ERDataset_GTK::GetTypeKey() const { return g_ERDataset_TypeKey[0]; }
