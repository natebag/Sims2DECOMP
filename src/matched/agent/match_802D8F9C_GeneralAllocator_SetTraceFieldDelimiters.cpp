struct GA_STFD {
    char pad[0x484];
    unsigned char m_delim1;
    unsigned char m_delim2;
    void SetTraceFieldDelimiters(unsigned char d1, unsigned char d2);
};
void GA_STFD::SetTraceFieldDelimiters(unsigned char d1, unsigned char d2) {
    m_delim1 = d1;
    m_delim2 = d2;
}
