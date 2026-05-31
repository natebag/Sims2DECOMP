// 0x800A32AC BString2::operator[](unsigned int) (200 B)
// FLAGS:
//
// Wide-char sibling of BString::operator[] (0x8009EC48). Range-check, detach a
// shared rep (copy-on-write), return a reference into the writable buffer.
// data() is inlined (length()-guarded m_data load), as the DOL emits.

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
    basic_string_ref2(unsigned short* s, unsigned int len, unsigned int cap);
    void* operator new(unsigned int n) { return MainHeap()->Malloc(n, 0); }
};

struct BString2 {
    basic_string_ref2* m_rep;
    unsigned int    length() const;
    unsigned int    ref_count() const;
    unsigned short* point();
    void            delete_ref();
    unsigned short* data() const { if (length() != 0) return m_rep->m_data; return 0; }
    unsigned short& operator[](unsigned int i);
};

unsigned short& BString2::operator[](unsigned int i)
{
    if (i >= length())
        basic_string_ref2__throwrange();
    if (ref_count() > 1) {
        basic_string_ref2* rep = new basic_string_ref2(data(), length(), length());
        delete_ref();
        m_rep = rep;
    }
    return point()[i];
}
