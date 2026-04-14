/* 0x8009EFC0 (88 bytes) - BString::find(BString &, unsigned int) const */

class BString {
public:
    char *data(void) const;
    unsigned int length(void) const;
    unsigned int find_str(char *s, unsigned int pos, unsigned int len) const;
    unsigned int find(BString &str, unsigned int pos) const;
};

unsigned int BString::find(BString &str, unsigned int pos) const
{
    char *d = str.data();
    unsigned int len = str.length();
    return find_str(d, pos, len);
}
