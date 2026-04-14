/* 0x8009F3B0 (88 bytes) - BString::find_last_of(BString &, unsigned int) const */

class BString {
public:
    char *data(void) const;
    unsigned int length(void) const;
    unsigned int find_last_of_str(char *s, unsigned int pos, unsigned int len) const;
    unsigned int find_last_of(BString &str, unsigned int pos) const;
};

unsigned int BString::find_last_of(BString &str, unsigned int pos) const
{
    char *d = str.data();
    unsigned int len = str.length();
    return find_last_of_str(d, pos, len);
}
