// 0x80227820 EIGameInstance::GetTypeVersion (12B) const
struct VerBlock_EIGameInstance { unsigned short ver[256]; };
extern VerBlock_EIGameInstance g_EIGameInstance_TypeVersion[3];
struct EIGameInstance_GTV { unsigned short GetTypeVersion() const; };
unsigned short EIGameInstance_GTV::GetTypeVersion() const { return g_EIGameInstance_TypeVersion[0].ver[0]; }
