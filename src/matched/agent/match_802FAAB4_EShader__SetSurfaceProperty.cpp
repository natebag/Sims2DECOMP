class EShader {
public:
    int m_pad;
    unsigned int m_surfaceProperties;
    void SetSurfaceProperty(unsigned int);
};
void EShader::SetSurfaceProperty(unsigned int prop) { m_surfaceProperties |= prop; }
