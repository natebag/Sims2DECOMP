// 0x803C9818 EAnimNodeDataPos::GetTypeKey (12B) const
extern int g_EAnimNodeDataPos_TypeKey[3];
struct EAnimNodeDataPos_GTK { int GetTypeKey() const; };
int EAnimNodeDataPos_GTK::GetTypeKey() const { return g_EAnimNodeDataPos_TypeKey[0]; }
