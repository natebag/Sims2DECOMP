// 0x8032054C ERShader::GetTypeKey (12B) const
extern int g_ERShader_TypeKey[3];
struct ERShader_GTK { int GetTypeKey() const; };
int ERShader_GTK::GetTypeKey() const { return g_ERShader_TypeKey[0]; }
