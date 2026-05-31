/* BString2::compare(const BString2&, unsigned int, unsigned int) const - 0x800A4038 (152 bytes) */

struct BString2Rep {
    unsigned short *m_data;
    int m_length;
};

struct BString2 {
    BString2Rep *m_rep;

    int length(void) const;
    unsigned short *data(void) const { if (length() != 0) return m_rep->m_data; return 0; }
    int compare_str(unsigned int pos, const unsigned short *s, unsigned int count, unsigned int slen) const;
    int compare(const BString2 &other, unsigned int pos, unsigned int n) const;
};

int BString2::compare(const BString2 &other, unsigned int pos, unsigned int n) const {
    unsigned int count;
    if (n > (unsigned int)(length() - pos))
        count = length() - pos;
    else
        count = n;
    return compare_str(pos, other.data(), count, other.length());
}
