/* BString::insert(unsigned int, const BString&, unsigned int, unsigned int) - 0x8009E1B4 (140 bytes) */

struct BString {
    int length(void) const;
    char *data(void) const;
    void insert_str(unsigned int pos, const char *s, unsigned int count);
    BString &insert(unsigned int pos, const BString &str, unsigned int opos, unsigned int n);
};

extern void basic_string_ref__throwrange(void);

BString &BString::insert(unsigned int pos, const BString &str, unsigned int opos, unsigned int n) {
    if (opos > (unsigned int)str.length())
        basic_string_ref__throwrange();

    unsigned int count;
    if (n > (unsigned int)(str.length() - opos))
        count = str.length() - opos;
    else
        count = n;

    insert_str(pos, str.data() + opos, count);
    return *this;
}
