// 0x80030560 EIWallPart::GetTypeInfo(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_EIWallPartTypeInfo;
struct EIWallPart { EATypeInfo* GetTypeInfo(); };
EATypeInfo* EIWallPart::GetTypeInfo() { return &g_EIWallPartTypeInfo; }
