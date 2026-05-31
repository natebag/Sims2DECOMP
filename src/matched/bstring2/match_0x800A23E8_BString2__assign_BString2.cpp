/* BString2::assign(const BString2&, unsigned int, unsigned int) - 0x800A23E8 (224 bytes) */

struct BString2Rep {
    unsigned short *m_data;
    int m_length;
    int m_capacity;
    int m_refCount;
};

struct BString2 {
    BString2Rep *m_rep;

    int length(void) const;
    unsigned short *data(void) const { if (length() != 0) return m_rep->m_data; return 0; }
    int ref_count(void) const;
    void delete_ref(void);
    void assign_str(const unsigned short *s, unsigned int len);
    BString2 &assign(const BString2 &str, unsigned int pos, unsigned int n);
};

extern void basic_string_ref2__throwrange(void);

BString2 &BString2::assign(const BString2 &str, unsigned int pos, unsigned int n) {
    if (pos > (unsigned int)str.length())
        basic_string_ref2__throwrange();

    unsigned int count;
    if (n > (unsigned int)(str.length() - pos))
        count = str.length() - pos;
    else
        count = n;

    if (count == (unsigned int)str.length() && str.ref_count() != -1) {
        delete_ref();
        m_rep = str.m_rep;
        ++m_rep->m_refCount;
    } else {
        assign_str(str.data() + pos, count);
    }
    return *this;
}
