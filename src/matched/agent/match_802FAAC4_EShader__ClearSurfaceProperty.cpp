class EShader {
public:
    int m_pad;
    unsigned int m_surfaceProperties;
    void ClearSurfaceProperty(unsigned int);
};
void EShader::ClearSurfaceProperty(unsigned int prop) { m_surfaceProperties &= ~prop; }
