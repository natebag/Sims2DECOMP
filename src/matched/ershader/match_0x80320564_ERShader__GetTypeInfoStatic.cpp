// 0x80320564 ERShader::GetTypeInfoStatic (12B)
struct TypeInfo_ERShader { char data[256]; };
extern TypeInfo_ERShader g_ERShader_TypeInfo[3];
TypeInfo_ERShader* ERShader_GetTypeInfoStatic() { return &g_ERShader_TypeInfo[0]; }
