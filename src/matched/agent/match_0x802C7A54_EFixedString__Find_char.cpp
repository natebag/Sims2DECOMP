// EFixedString::Find(char) const - 0x802C7A54 (64B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int Find(char c) const;
};

int EFixedString::Find(char c) const {
    char* p = m_pBuffer;
    int idx = 0;
    unsigned char raw = *(unsigned char*)p;
    if (!raw) goto not_found;
    do {
        if ((signed char)raw == c) return idx;
        raw = *(unsigned char*)++p;
        idx++;
    } while (raw);
not_found:
    return -1;
}
