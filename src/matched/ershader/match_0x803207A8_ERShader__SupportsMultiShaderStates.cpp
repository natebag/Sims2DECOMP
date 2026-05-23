struct ERShader {
    char _p[0x3c];
    int m_multiShaderState;
    int SupportsMultiShaderStates();
};
int ERShader::SupportsMultiShaderStates() { return m_multiShaderState == 2; }
