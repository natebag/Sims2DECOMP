/* BString2::operator+=(const BString2&) - 0x800A1F5C (104 bytes) */

struct BString2Rep {
    unsigned short *m_data;
    int m_length;
};

struct BString2 {
    BString2Rep *m_rep;

    int length(void) const;
    unsigned short *data(void) const { if (length() != 0) return m_rep->m_data; return 0; }
    void append_str(const unsigned short *s, unsigned int len);
    BString2 &operator+=(const BString2 &other);
};

BString2 &BString2::operator+=(const BString2 &other) {
    append_str(other.data(), other.length());
    return *this;
}
