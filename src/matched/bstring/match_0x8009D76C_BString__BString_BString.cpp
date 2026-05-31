// 0x8009D76C BString::BString(BString&, unsigned int, unsigned int) (200 B)
// FLAGS: -fno-schedule-insns
//
// Substring copy ctor: builds *this from n chars of src starting at pos.
// Range-checks pos, clamps n to the available tail, then either shares src's
// rep (whole-string && shareable) or deep-copies into a fresh rep.

struct BString;

struct EAHeap {
    void* Malloc(unsigned int size, int flags);
};
extern EAHeap* MainHeap();

extern void basic_string_ref__throwrange();

struct basic_string_ref {
    char* m_data;
    int   m_length;
    int   m_capacity;
    int   m_ref_count;
    basic_string_ref(BString& src, unsigned int offset, unsigned int count);
    void* operator new(unsigned int n) { return MainHeap()->Malloc(n, 0); }
};

struct BString {
    basic_string_ref* m_rep;
    unsigned int length() const;
    int          ref_count() const;
    BString(BString& src, unsigned int pos, unsigned int n);
};

BString::BString(BString& src, unsigned int pos, unsigned int n)
{
    if (pos > src.length())
        basic_string_ref__throwrange();
    if (n > src.length() - pos)
        n = src.length() - pos;

    if (n == src.length() && src.ref_count() != -1) {
        m_rep = src.m_rep;
        ++m_rep->m_ref_count;
    } else {
        m_rep = new basic_string_ref(src, pos, n);
    }
}
