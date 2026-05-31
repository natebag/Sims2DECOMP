/* BString2::append(const BString2&, unsigned int, unsigned int) - 0x800A2150 (168 bytes) */

struct BString2Rep {
    unsigned short *m_data;
    int m_length;
};

struct BString2 {
    BString2Rep *m_rep;

    int length(void) const;
    unsigned short *data(void) const { if (length() != 0) return m_rep->m_data; return 0; }
    void append_str(const unsigned short *s, unsigned int len);
    BString2 &append(const BString2 &other, unsigned int pos, unsigned int n);
};

extern void basic_string_ref2__throwrange(void);

BString2 &BString2::append(const BString2 &other, unsigned int pos, unsigned int n) {
    if (pos > (unsigned int)other.length())
        basic_string_ref2__throwrange();

    const unsigned short *p = other.data() + pos;

    unsigned int count;
    if (n > (unsigned int)(other.length() - pos))
        count = other.length() - pos;
    else
        count = n;

    append_str(p, count);
    return *this;
}
