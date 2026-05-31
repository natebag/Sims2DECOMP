/* BString2::insert(unsigned int, const BString2&, unsigned int, unsigned int) - 0x800A2634 (168 bytes) */

struct BString2Rep {
    unsigned short *m_data;
    int m_length;
};

struct BString2 {
    BString2Rep *m_rep;

    int length(void) const;
    unsigned short *data(void) const { if (length() != 0) return m_rep->m_data; return 0; }
    void insert_str(unsigned int pos, const unsigned short *s, unsigned int count);
    BString2 &insert(unsigned int pos, const BString2 &str, unsigned int opos, unsigned int n);
};

extern void basic_string_ref2__throwrange(void);

BString2 &BString2::insert(unsigned int pos, const BString2 &str, unsigned int opos, unsigned int n) {
    if (opos > (unsigned int)str.length())
        basic_string_ref2__throwrange();

    unsigned int count;
    if (n > (unsigned int)(str.length() - opos))
        count = str.length() - opos;
    else
        count = n;

    insert_str(pos, str.data() + opos, count);
    return *this;
}
