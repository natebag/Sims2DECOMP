/* BString::replace(unsigned int, unsigned int, char*) - 0x8009E7C0 (132 bytes) */

struct BString {
    int length(void) const;
    void replace_str(unsigned int count, unsigned int pos, char *s, unsigned int slen);
    BString &replace(unsigned int pos, unsigned int n1, char *s);
};

extern unsigned int strlen(const char *s);

BString &BString::replace(unsigned int pos, unsigned int n1, char *s) {
    unsigned int count;
    if (n1 > (unsigned int)(length() - pos))
        count = length() - pos;
    else
        count = n1;

    unsigned int slen;
    if (s != 0)
        slen = strlen(s);
    else
        slen = 0;

    replace_str(count, pos, s, slen);
    return *this;
}
