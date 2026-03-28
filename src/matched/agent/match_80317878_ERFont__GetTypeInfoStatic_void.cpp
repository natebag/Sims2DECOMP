struct TypeInfo { int data[4]; };
TypeInfo s_ERFont_typeInfo = { {1, 2, 3, 4} };
class ERFont { public: static TypeInfo *GetTypeInfoStatic(); };
TypeInfo *ERFont::GetTypeInfoStatic() { return &s_ERFont_typeInfo; }
