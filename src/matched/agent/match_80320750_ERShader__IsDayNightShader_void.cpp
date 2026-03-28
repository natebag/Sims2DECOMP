class ERShader { char pad[88]; unsigned int m_flags; public: int IsDayNightShader(); };
int ERShader::IsDayNightShader() { return (m_flags >> 5) & 1; }
