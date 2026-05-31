/* BString::replace(unsigned int, unsigned int, const BString&, unsigned int, unsigned int) - 0x8009E688 (160 bytes) */

struct BString {
    int length(void) const;
    char *data(void) const;
    void replace_str(unsigned int count1, unsigned int pos, const char *s, unsigned int count2);
    BString &replace(unsigned int pos, unsigned int n1, const BString &str, unsigned int opos, unsigned int n2);
};

extern void basic_string_ref__throwrange(void);

BString &BString::replace(unsigned int pos, unsigned int n1, const BString &str, unsigned int opos, unsigned int n2) {
    if (opos > (unsigned int)str.length())
        basic_string_ref__throwrange();

    unsigned int count1;
    if (n1 > (unsigned int)(length() - pos))
        count1 = length() - pos;
    else
        count1 = n1;

    unsigned int count2;
    if (n2 > (unsigned int)(str.length() - opos))
        count2 = str.length() - opos;
    else
        count2 = n2;

    replace_str(count1, pos, str.data() + opos, count2);
    return *this;
}
