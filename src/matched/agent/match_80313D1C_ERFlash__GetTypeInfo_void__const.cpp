struct TypeInfo { int data[4]; };
TypeInfo s_ERFlash_typeInfo = { {1, 2, 3, 4} };
class ERFlash { public: TypeInfo *GetTypeInfo() const; };
TypeInfo *ERFlash::GetTypeInfo() const { return &s_ERFlash_typeInfo; }
