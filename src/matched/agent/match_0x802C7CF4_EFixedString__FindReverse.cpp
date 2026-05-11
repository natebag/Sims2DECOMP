// EFixedString::FindReverse(char) const - 0x802C7CF4 (100B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int GetLength() const;
    int FindReverse(char c) const;
};

int EFixedString::FindReverse(char c) const {
    int n = GetLength();
    int i = n - 1;
    char* p = m_pBuffer + i;
    if (i < 0) goto done;
loop:
    if ((signed char)*p == c) return i;
    p--;
    i--;
    if (i >= 0) goto loop;
done:
    return -1;
}
