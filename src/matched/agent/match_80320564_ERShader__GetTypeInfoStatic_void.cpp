struct TypeInfo { int data[4]; };
TypeInfo s_ERShader_typeInfo = { {1, 2, 3, 4} };
class ERShader { public: static TypeInfo *GetTypeInfoStatic(); };
TypeInfo *ERShader::GetTypeInfoStatic() { return &s_ERShader_typeInfo; }
