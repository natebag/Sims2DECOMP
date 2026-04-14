// 0x80320534 ERShader::GetTypeInfo (12B) const
struct TypeInfo_ERShader { char data[256]; };
extern TypeInfo_ERShader g_ERShader_TypeInfo[3];
struct ERShader_GTI { TypeInfo_ERShader* GetTypeInfo() const; };
TypeInfo_ERShader* ERShader_GTI::GetTypeInfo() const { return &g_ERShader_TypeInfo[0]; }
