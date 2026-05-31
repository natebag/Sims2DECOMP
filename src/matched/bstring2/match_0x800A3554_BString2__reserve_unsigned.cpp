// 0x800A3554 BString2::reserve(unsigned int) (152 B)
// FLAGS: -fno-schedule-insns
//
// Wide-char sibling of BString::reserve (0x8009EE98). Same grow-rep logic; the
// difference is BString2::data() is inlined (the DOL emits the length()-guarded
// m_data load inline rather than an external call).

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
    basic_string_ref2(unsigned short* s, unsigned int len, unsigned int cap);
    void* operator new(unsigned int n) { return MainHeap()->Malloc(n, 0); }
};

struct BString2 {
    basic_string_ref2* m_rep;
    unsigned int    length() const;
    unsigned int    reserve() const;
    void            delete_ref();
    unsigned short* data() const { if (length() != 0) return m_rep->m_data; return 0; }
    void            reserve(unsigned int n);
};

void BString2::reserve(unsigned int n)
{
    if (n == (unsigned int)-1)
        basic_string_ref2__throwlength();

    if (n + 1 > reserve()) {
        basic_string_ref2* rep = new basic_string_ref2(data(), length(), n);
        delete_ref();
        m_rep = rep;
    }
}
