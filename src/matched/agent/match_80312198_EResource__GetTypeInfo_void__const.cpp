struct TypeInfo { int data[4]; };
TypeInfo s_EResource_typeInfo = { {1, 2, 3, 4} };
class EResource { public: TypeInfo *GetTypeInfo() const; };
TypeInfo *EResource::GetTypeInfo() const { return &s_EResource_typeInfo; }
