// EFixedString::Compare(char*) const - 0x802C7690 (84B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int Compare(char* other) const;
};

int EFixedString::Compare(char* other) const {
    char* p = m_pBuffer;
    do {
        signed char a = *(signed char*)p;
        signed char b = *(signed char*)other;
        if (a < b) return -1;
        if (a > b) return 1;
        char c = *++p;
        ++other;
        if (!c) {
            if (!*other) return 0;
        }
    } while (true);
}
