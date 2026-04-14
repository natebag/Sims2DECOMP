// 0x803C1438 EStorable::GetTypeKey (12B) const
extern int g_EStorable_TypeKey[3];
struct EStorable_GTK { int GetTypeKey() const; };
int EStorable_GTK::GetTypeKey() const { return g_EStorable_TypeKey[0]; }
