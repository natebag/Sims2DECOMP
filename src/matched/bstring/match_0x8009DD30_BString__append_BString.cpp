/* BString::append(const BString&, unsigned int, unsigned int) - 0x8009DD30 (140 bytes) */

struct BString {
    int length(void) const;
    char *data(void) const;
    void append_str(const char *s, unsigned int len);
    BString &append(const BString &other, unsigned int pos, unsigned int n);
};

extern void basic_string_ref__throwrange(void);

BString &BString::append(const BString &other, unsigned int pos, unsigned int n) {
    if (pos > (unsigned int)other.length())
        basic_string_ref__throwrange();

    const char *p = other.data() + pos;

    unsigned int count;
    if (n > (unsigned int)(other.length() - pos))
        count = other.length() - pos;
    else
        count = n;

    append_str(p, count);
    return *this;
}
