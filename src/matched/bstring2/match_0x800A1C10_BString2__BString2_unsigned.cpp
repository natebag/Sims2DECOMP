// 0x800A1C10 BString2::BString2(unsigned short*, unsigned int, unsigned int) (108 B)
// FLAGS:
//
// Wide-char sibling of BString::BString(char*,uint,uint) (0x8009D834).
// Construct from a wide-string slice [pos, pos+n). Overflow-guards pos+n
// against the npos sentinel, then deep-copies into a fresh rep (delegates to
// the wchar*-range rep ctor via external bl, so dodges the allocator-wall).

struct EAHeap {
    void* Malloc(unsigned int size, int flags);
};
extern EAHeap* MainHeap();

extern void basic_string_ref2__throwlength();

struct basic_string_ref2 {
    unsigned short* m_data;
    int             m_length;
    int             m_capacity;
    int             m_ref_count;
    basic_string_ref2(unsigned short* s, unsigned int from, unsigned int to);
    void* operator new(unsigned int n) { return MainHeap()->Malloc(n, 0); }
};

struct BString2 {
    basic_string_ref2* m_rep;
    BString2(unsigned short* s, unsigned int pos, unsigned int n);
};

BString2::BString2(unsigned short* s, unsigned int pos, unsigned int n)
{
    if (pos >= ~n)
        basic_string_ref2__throwlength();
    m_rep = new basic_string_ref2(s, pos, pos + n);
}
