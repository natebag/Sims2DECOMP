struct TypeInfo { int data[4]; };
TypeInfo s_ERTexture_typeInfo = { {1, 2, 3, 4} };
class ERTexture { public: TypeInfo *GetTypeInfo() const; };
TypeInfo *ERTexture::GetTypeInfo() const { return &s_ERTexture_typeInfo; }
