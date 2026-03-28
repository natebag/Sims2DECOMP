class ERShader { char pad[88]; unsigned int m_flags; public: int IsStateChangePending(); };
int ERShader::IsStateChangePending() { return (m_flags >> 2) & 1; }
