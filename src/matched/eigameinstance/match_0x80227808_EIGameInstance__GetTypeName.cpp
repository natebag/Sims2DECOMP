// 0x80227808 EIGameInstance::GetTypeName (12B) const
extern char* g_EIGameInstance_TypeName[3];
struct EIGameInstance_GTN { const char* GetTypeName() const; };
const char* EIGameInstance_GTN::GetTypeName() const { return g_EIGameInstance_TypeName[0]; }
