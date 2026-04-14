// 0x80320540 ERShader::GetTypeName (12B) const
extern char* g_ERShader_TypeName[3];
struct ERShader_GTN { const char* GetTypeName() const; };
const char* ERShader_GTN::GetTypeName() const { return g_ERShader_TypeName[0]; }
