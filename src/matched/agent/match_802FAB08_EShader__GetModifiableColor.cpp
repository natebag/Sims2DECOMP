class EShader {
public:
    char m_pad[64];
    unsigned int m_modifiableColors[4];
    unsigned int GetModifiableColor(unsigned int index) const;
};
unsigned int EShader::GetModifiableColor(unsigned int index) const {
    return m_modifiableColors[index];
}
