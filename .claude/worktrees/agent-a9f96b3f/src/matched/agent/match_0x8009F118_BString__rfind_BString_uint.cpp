/* 0x8009F118 (88 bytes) - BString::rfind(BString &, unsigned int) const */

class BString {
public:
    char *data(void) const;
    unsigned int length(void) const;
    unsigned int rfind_str(char *s, unsigned int pos, unsigned int len) const;
    unsigned int rfind(BString &str, unsigned int pos) const;
};

unsigned int BString::rfind(BString &str, unsigned int pos) const
{
    char *d = str.data();
    unsigned int len = str.length();
    return rfind_str(d, pos, len);
}
