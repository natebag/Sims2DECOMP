class EShader {
public:
    int m_pad;
    unsigned int m_surfaceProperties;
    bool IsSurface(unsigned int prop) const;
};
bool EShader::IsSurface(unsigned int prop) const {
    return (m_surfaceProperties & prop) != 0;
}
