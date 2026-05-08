// EFixedString::operator+=(char) - 0x802C7A18 (60B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    EFixedString& operator+=(char c);
    EFixedString& operator+=(char* s);
};

EFixedString& EFixedString::operator+=(char c) {
    short wc = (short)(c << 8);
    operator+=((char*)&wc);
    return *this;
}
