class EShader {
public:
    int m_pad;
    unsigned int m_surfaceProperties;
    void UndoOverrideTexture();
};
void EShader::UndoOverrideTexture() {
    m_surfaceProperties &= ~0x02000000;
}
