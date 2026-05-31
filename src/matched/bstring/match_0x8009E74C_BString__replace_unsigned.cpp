/* BString::replace(unsigned int, unsigned int, const char*, unsigned int) - 0x8009E74C (116 bytes) */

struct BString {
    int length(void) const;
    void replace_str(unsigned int count, unsigned int pos, const char *s, unsigned int n2);
    BString &replace(unsigned int pos, unsigned int n1, const char *s, unsigned int n2);
};

BString &BString::replace(unsigned int pos, unsigned int n1, const char *s, unsigned int n2) {
    unsigned int count;
    if (n1 > (unsigned int)(length() - pos))
        count = length() - pos;
    else
        count = n1;

    replace_str(count, pos, s, n2);
    return *this;
}
