/* BString2::replace(unsigned int, unsigned int, const unsigned short*, unsigned int) - 0x800A2CCC (116 bytes) */

struct BString2 {
    int length(void) const;
    void replace_str(unsigned int count, unsigned int pos, const unsigned short *s, unsigned int n2);
    BString2 &replace(unsigned int pos, unsigned int n1, const unsigned short *s, unsigned int n2);
};

BString2 &BString2::replace(unsigned int pos, unsigned int n1, const unsigned short *s, unsigned int n2) {
    unsigned int count;
    if (n1 > (unsigned int)(length() - pos))
        count = length() - pos;
    else
        count = n1;

    replace_str(count, pos, s, n2);
    return *this;
}
