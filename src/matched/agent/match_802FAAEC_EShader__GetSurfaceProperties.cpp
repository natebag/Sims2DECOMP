class EShader {
public:
    int m_pad;
    int m_pSurfaceProperties;
    int GetSurfaceProperties() const;
};
int EShader::GetSurfaceProperties() const { return m_pSurfaceProperties; }
