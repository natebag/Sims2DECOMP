// 0x80048410 EIFloor::GetTypeKey (12B) const
extern int g_EIFloor_TypeKey[3];
struct EIFloor_GTK { int GetTypeKey() const; };
int EIFloor_GTK::GetTypeKey() const { return g_EIFloor_TypeKey[0]; }
