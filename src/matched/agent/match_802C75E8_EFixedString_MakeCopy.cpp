struct EFixedString_MC {
    char* m_buffer;
    void MakeCopy(char c);
};

void EFixedString_MC::MakeCopy(char c) {
    m_buffer[0] = c;
    m_buffer[1] = 0;
}
