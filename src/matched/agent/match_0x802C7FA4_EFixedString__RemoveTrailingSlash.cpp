// EFixedString::RemoveTrailingSlash() - 0x802C7FA4 (144B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int GetLength() const;
    void Left(EFixedString& out, int count) const;
    void RemoveTrailingSlash();
};

void EFixedString::RemoveTrailingSlash() {
    int n = GetLength();
    if (!n) goto done;
    {
        char* end = (char*)(n + (int)m_pBuffer);
        if (*(end - 1) != '\\') goto done;
        if (n == 1) goto done;
        if (n != 3) goto do_left;
        if (m_pBuffer[1] != ':') goto do_left;
        {
            unsigned char first = m_pBuffer[0];
            if ((unsigned)(first - 'a') <= 25) goto done;
            if ((unsigned)(first - 'A') <= 25) goto done;
        }
do_left:
        Left(*this, n - 1);
    }
done:;
}
