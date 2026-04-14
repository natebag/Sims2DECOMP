/* EFixedString::FindReverse(char) const - 0x802C7CF4 (100 bytes) */

struct EFixedString {
    char *m_str;

    int GetLength() const;
    int FindReverse(char c) const;
};

int EFixedString::FindReverse(char c) const
{
    int len = GetLength();
    char *p = m_str;
    int i = len - 1;
    char *q = p + i;
    while (i >= 0) {
        if (*q == c)
            return i;
        q--;
        i--;
    }
    return -1;
}
