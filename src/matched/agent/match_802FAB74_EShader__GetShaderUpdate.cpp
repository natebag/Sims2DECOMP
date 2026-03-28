class EShader {
public:
    char m_pad[232];
    int m_pShaderUpdate;
    int GetShaderUpdate() const;
};
int EShader::GetShaderUpdate() const { return m_pShaderUpdate; }
