// 0x800A1B48 BString2::BString2(BString2&, unsigned int, unsigned int) (200 B)
// FLAGS: -fno-schedule-insns
//
// Wide-char sibling of BString::BString(BString&,uint,uint) (0x8009D76C).
// Substring copy ctor: range-check pos, clamp n to the available tail, then
// share src's rep (whole-string && shareable) or deep-copy into a fresh rep.

struct BString2;

struct EAHeap {
    void* Malloc(unsigned int size, int flags);
};
extern EAHeap* MainHeap();

extern void basic_string_ref2__throwrange();

struct basic_string_ref2 {
    unsigned short* m_data;
    int             m_length;
    int             m_capacity;
    int             m_ref_count;
    basic_string_ref2(BString2& src, unsigned int offset, unsigned int count);
    void* operator new(unsigned int n) { return MainHeap()->Malloc(n, 0); }
};

struct BString2 {
    basic_string_ref2* m_rep;
    unsigned int length() const;
    int          ref_count() const;
    BString2(BString2& src, unsigned int pos, unsigned int n);
};

BString2::BString2(BString2& src, unsigned int pos, unsigned int n)
{
    if (pos > src.length())
        basic_string_ref2__throwrange();
    if (n > src.length() - pos)
        n = src.length() - pos;

    if (n == src.length() && src.ref_count() != -1) {
        m_rep = src.m_rep;
        ++m_rep->m_ref_count;
    } else {
        m_rep = new basic_string_ref2(src, pos, n);
    }
}
