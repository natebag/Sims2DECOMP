// 0x800568AC ISimInstance::GetTypeInfo (12b)
struct ETypeInfo { int data[4]; };
extern ETypeInfo g_ISimInstance_typeInfo;
ETypeInfo* ISimInstance_GetTypeInfo() { return &g_ISimInstance_typeInfo; }
