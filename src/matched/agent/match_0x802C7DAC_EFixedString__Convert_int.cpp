// EFixedString::Convert(int) - 0x802C7DAC (88B)

extern int Sprintf(char* dst, char* fmt, ...);

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    EFixedString* Convert(int value);
};

EFixedString* EFixedString::Convert(int value) {
    Sprintf(m_pBuffer, "%d", value);
    m_pBuffer[m_nMaxSize - 1] = 0;
    return this;
}
