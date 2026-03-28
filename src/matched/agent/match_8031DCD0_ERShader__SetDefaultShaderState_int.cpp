static unsigned char s_defaultShaderState;
class ERShader { public: static void SetDefaultShaderState(int); };
void ERShader::SetDefaultShaderState(int val) { s_defaultShaderState = val; }
