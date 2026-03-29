struct ETypeInfo { int data[4]; };
extern ETypeInfo g_typeInfo;
int GetTypeName() { return g_typeInfo.data[3]; }
