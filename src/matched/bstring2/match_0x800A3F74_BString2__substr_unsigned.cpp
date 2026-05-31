// 0x800A3F74 BString2::substr(unsigned int, unsigned int) const (196 B)
// FLAGS: -fno-schedule-insns2
//
// Wide-char sibling of BString::substr (0x8009F770). Return the substring
// [pos, pos+n) (n clamped to the tail); empty source yields an empty string.
// Result built in the return slot (NRVO). data() is inlined.

extern void basic_string_ref2__throwrange();

struct basic_string_ref2 {
    unsigned short* m_data;
    int             m_length;
    int             m_capacity;
    int             m_ref_count;
};

struct BString2 {
    basic_string_ref2* m_rep;
    unsigned int    length() const;
    unsigned short* data() const { if (length() != 0) return m_rep->m_data; return 0; }
    BString2(unsigned short* s, unsigned int n);
    BString2();
    BString2 substr(unsigned int pos, unsigned int n) const;
};

BString2 BString2::substr(unsigned int pos, unsigned int n) const
{
    if (pos > length())
        basic_string_ref2__throwrange();
    if (length() != 0)
        return BString2(data() + pos, (n > length() - pos) ? length() - pos : n);
    return BString2();
}
