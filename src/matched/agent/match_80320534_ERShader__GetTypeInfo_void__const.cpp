struct TypeInfo { int data[4]; };
TypeInfo s_ERShader_typeInfo = { {1, 2, 3, 4} };
class ERShader { public: TypeInfo *GetTypeInfo() const; };
TypeInfo *ERShader::GetTypeInfo() const { return &s_ERShader_typeInfo; }
