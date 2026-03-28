class EShader {
public:
    int m_pad;
    unsigned int m_surfaceProperties;
    bool IsCylindricalFacer() const;
};
bool EShader::IsCylindricalFacer() const {
    return (m_surfaceProperties >> 3) & 1;
}
