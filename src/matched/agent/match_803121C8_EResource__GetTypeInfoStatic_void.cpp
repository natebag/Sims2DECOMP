struct TypeInfo { int data[4]; };
TypeInfo s_EResource_typeInfo = { {1, 2, 3, 4} };
class EResource { public: static TypeInfo *GetTypeInfoStatic(); };
TypeInfo *EResource::GetTypeInfoStatic() { return &s_EResource_typeInfo; }
