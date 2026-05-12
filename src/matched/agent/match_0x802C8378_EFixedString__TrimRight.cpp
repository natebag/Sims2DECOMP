// EFixedString::TrimRight(char) - 0x802C8378 (164B)
// v6: return EFixedString& to force shared epilogue mr r3,r30 after Left

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int GetLength() const;
    void Left(EFixedString& out, int count) const;
    EFixedString& TrimRight(char c);
};

EFixedString& EFixedString::TrimRight(char c) {
    int n = GetLength();
    if (!n) goto done;
    {
        char* end = (char*)(n + (int)m_pBuffer);
        if (*(end - 1) != c) goto done;
        if (!--n) goto call_left;
        if (m_pBuffer[n - 1] != c) goto call_left;
        while (--n && m_pBuffer[n - 1] == c)
            ;
    call_left:
        Left(*this, n);
    }
done:
    return *this;
}
