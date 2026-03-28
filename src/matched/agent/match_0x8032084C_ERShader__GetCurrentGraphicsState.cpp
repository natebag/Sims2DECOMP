struct ERShader {
    char _pad[0x50];
    unsigned char m_currentGraphicsState;
    unsigned char GetCurrentGraphicsState();
};
unsigned char ERShader::GetCurrentGraphicsState() { return m_currentGraphicsState; }
