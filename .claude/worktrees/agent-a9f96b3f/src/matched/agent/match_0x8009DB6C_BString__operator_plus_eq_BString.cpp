/* 0x8009DB6C (84 bytes) - BString::operator+=(BString &) */

class BString {
public:
    char *data(void) const;
    unsigned int length(void) const;
    void append_str(char *str, unsigned int len);
    BString &operator+=(BString &rhs);
};

BString &BString::operator+=(BString &rhs)
{
    char *d = rhs.data();
    unsigned int len = rhs.length();
    append_str(d, len);
    return *this;
}
