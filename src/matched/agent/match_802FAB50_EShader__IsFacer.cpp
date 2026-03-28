class EShader {
public:
    int m_pad;
    unsigned int m_surfaceProperties;
    bool IsFacer() const;
};
bool EShader::IsFacer() const {
    return (m_surfaceProperties & 0x000C) != 0;
}
