// 0x80227430 EIDirLight::GetTypeKey (12B) const
extern int g_EIDirLight_TypeKey[3];
struct EIDirLight_GTK { int GetTypeKey() const; };
int EIDirLight_GTK::GetTypeKey() const { return g_EIDirLight_TypeKey[0]; }
