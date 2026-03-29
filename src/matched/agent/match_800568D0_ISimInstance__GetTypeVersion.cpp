struct ETypeInfo { char data[24]; unsigned short m_ver; };
extern ETypeInfo g_typeInfo;
int GetTypeVersion() { return g_typeInfo.m_ver; }
