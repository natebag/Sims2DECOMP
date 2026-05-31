// 0x8009F770 BString::substr(unsigned int, unsigned int) const (168 B)
// FLAGS: -fno-schedule-insns2
//
// Return the substring [pos, pos+n) (n clamped to the available tail). Range-
// checks pos; an empty source yields an empty string. The result is built
// directly in the return slot (NRVO) via the char*-length ctor.

extern void basic_string_ref__throwrange();

struct basic_string_ref;

struct BString {
    basic_string_ref* m_rep;
    unsigned int length() const;
    char*        data() const;
    BString(char* s, unsigned int n);
    BString();
    BString substr(unsigned int pos, unsigned int n) const;
};

BString BString::substr(unsigned int pos, unsigned int n) const
{
    if (pos > length())
        basic_string_ref__throwrange();
    if (length() != 0)
        return BString(data() + pos, (n > length() - pos) ? length() - pos : n);
    return BString();
}
