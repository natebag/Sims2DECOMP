class ERShader { char pad[80]; unsigned char m_val; public: unsigned char GetCurrentGraphicsState(); };
unsigned char ERShader::GetCurrentGraphicsState() { return m_val; }
