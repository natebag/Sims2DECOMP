struct ETypeInfo { int data[5]; };
extern ETypeInfo g_typeInfo;
int GetTypeKey() { return g_typeInfo.data[4]; }
