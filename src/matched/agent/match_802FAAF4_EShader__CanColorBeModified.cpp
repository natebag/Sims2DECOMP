class EShader {
public:
    char m_pad1[116];
    unsigned int m_colorModFlags;
    char m_pad2[60];
    unsigned int m_colorModFlags2;
    bool CanColorBeModified() const;
};
bool EShader::CanColorBeModified() const {
    return ((m_colorModFlags | m_colorModFlags2) >> 5) & 1;
}
