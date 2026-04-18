/* ENgcRenderer::GetZTestSettings(unsigned char &, unsigned char &, unsigned char &) at 0x8034A538 (28B) */

struct ENgcRenderer_ZTS {
    char pad[0x4644];
    unsigned char m_zTestEnable;
    unsigned char m_zTestFunc;
    unsigned char m_zTestUpdate;
    void GetZTestSettings(unsigned char& a, unsigned char& b, unsigned char& c);
};

void ENgcRenderer_ZTS::GetZTestSettings(unsigned char& a, unsigned char& b, unsigned char& c) {
    a = m_zTestEnable;
    b = m_zTestFunc;
    c = m_zTestUpdate;
}
