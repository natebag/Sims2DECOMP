struct TypeInfo { int data[4]; };
TypeInfo s_ERFlash_typeInfo = { {1, 2, 3, 4} };
class ERFlash { public: static TypeInfo *GetTypeInfoStatic(); };
TypeInfo *ERFlash::GetTypeInfoStatic() { return &s_ERFlash_typeInfo; }
