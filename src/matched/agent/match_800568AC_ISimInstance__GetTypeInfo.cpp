struct ETypeInfo { int data[4]; };
extern ETypeInfo g_typeInfo;
ETypeInfo* GetTypeInfo() { return &g_typeInfo; }
