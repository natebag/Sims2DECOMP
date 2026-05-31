/* BString2::replace(unsigned int, unsigned int, unsigned short*) - 0x800A2D40 (132 bytes) */

struct BString2 {
    int length(void) const;
    void replace_str(unsigned int count, unsigned int pos, unsigned short *s, unsigned int slen);
    BString2 &replace(unsigned int pos, unsigned int n1, unsigned short *s);
};

extern unsigned int wcslen(const unsigned short *s);

BString2 &BString2::replace(unsigned int pos, unsigned int n1, unsigned short *s) {
    unsigned int count;
    if (n1 > (unsigned int)(length() - pos))
        count = length() - pos;
    else
        count = n1;

    unsigned int slen;
    if (s != 0)
        slen = wcslen(s);
    else
        slen = 0;

    replace_str(count, pos, s, slen);
    return *this;
}
