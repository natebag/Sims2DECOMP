// EFixedString::RemoveDriveLetter() - 0x802C8034 (116B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int GetLength() const;
    void Mid(EFixedString& out, int start, int count) const;
    void RemoveDriveLetter();
};

void EFixedString::RemoveDriveLetter() {
    if (GetLength() <= 2) return;
    char* p = m_pBuffer;
    if (p[1] != ':') return;
    unsigned int c = (unsigned int)(unsigned char)p[0];
    if ((c - 'a') > 25u && (c - 'A') > 25u) return;
    Mid(*this, 2, -1);
}
