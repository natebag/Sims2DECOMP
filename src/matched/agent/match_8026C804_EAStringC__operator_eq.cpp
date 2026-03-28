struct EAStringData {
    short m_refCount;
    unsigned short m_length;
    int m_pad;
    char m_data[1];
};

struct EAStringC {
    EAStringData *m_ptr;

    int operator==(EAStringC &other) const;
};

int memcmp(const void *, const void *, unsigned int);

int EAStringC::operator==(EAStringC &other) const {
    EAStringData *a = m_ptr;
    EAStringData *b = other.m_ptr;
    if (a->m_length != b->m_length) {
        return 0;
    }
    if (a == b) {
        return 1;
    }
    return memcmp(a->m_data, b->m_data, a->m_length) == 0;
}
