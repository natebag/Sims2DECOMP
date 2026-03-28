class ERShader { char pad[88]; unsigned int m_flags; public: int IsMultiShader() const; };
int ERShader::IsMultiShader() const { return (m_flags >> 1) & 1; }
