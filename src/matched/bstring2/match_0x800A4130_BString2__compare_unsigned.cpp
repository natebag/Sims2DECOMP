/* BString2::compare(const BString2*, unsigned int) const - 0x800A4130 (104 bytes) */

struct BString2Rep {
    unsigned short *m_data;
    int m_length;
};

struct BString2 {
    BString2Rep *m_rep;

    int length(void) const;
    int compare_str(unsigned int pos, const BString2 *other, unsigned int count, unsigned int olen) const;
    int compare(const BString2 *other, unsigned int pos) const;
};

int BString2::compare(const BString2 *other, unsigned int pos) const {
    unsigned int count = length() - pos;
    unsigned int olen;
    if (other != 0)
        olen = other->length();
    else
        olen = 0;
    return compare_str(pos, other, count, olen);
}
