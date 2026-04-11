// 0x800568B8 ISimInstance::GetTypeName (12b)
struct ETypeInfo { int data[4]; };
extern ETypeInfo g_ISimInstance_typeInfo;
int ISimInstance_GetTypeName() { return g_ISimInstance_typeInfo.data[3]; }
