// EFixedString::CompareNoCase(char*) const - 0x802C76E4 (124B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int CompareNoCase(char* other) const;
};

int EFixedString::CompareNoCase(char* other) const {
    const char* self = m_pBuffer;
    while (1) {
        signed char a = *self;
        if ((unsigned int)((int)a - 'a') <= 25u) a -= 32;
        signed char b = *other;
        if ((unsigned int)((int)b - 'a') <= 25u) b -= 32;
        if (a < b) return -1;
        if (a > b) return 1;
        unsigned char c = (unsigned char)*++self;
        other++;
        if (c != 0) continue;
        if (*(unsigned char*)other != 0) continue;
        return 0;
    }
}
