// EFixedString::Convert(float) - 0x802C7D58 (84B)

extern int Sprintf(char* dst, char* fmt, ...);

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    EFixedString* Convert(float value);
};

EFixedString* EFixedString::Convert(float value) {
    Sprintf(m_pBuffer, "%f", value);
    m_pBuffer[m_nMaxSize - 1] = 0;
    return this;
}
