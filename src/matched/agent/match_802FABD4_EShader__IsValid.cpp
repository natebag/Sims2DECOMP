class EShader {
public:
    char m_pad[228];
    unsigned int m_validTag;
    bool IsValid();
};
bool EShader::IsValid() {
    return m_validTag == 0x900DBEEF;
}
