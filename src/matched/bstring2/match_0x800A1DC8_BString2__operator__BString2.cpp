// 0x800A1DC8 BString2::operator=(BString2&) (152 B)
// FLAGS: -fno-schedule-insns
//
// Wide-char sibling of BString::operator= (0x8009D9D4). Self-assign guard;
// drop our current ref; share the source rep when shareable (ref_count()!=-1),
// else deep-copy into a freshly allocated rep.

struct BString2;

struct EAHeap {
    void* Malloc(unsigned int size, int flags);
};
extern EAHeap* MainHeap();

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
    int  length() const;
    int  ref_count() const;
    void delete_ref();
    BString2& operator=(const BString2& other);
};

BString2& BString2::operator=(const BString2& other)
{
    if (this != &other) {
        delete_ref();
        if (other.ref_count() != -1) {
            m_rep = other.m_rep;
            ++m_rep->m_ref_count;
        } else {
            m_rep = new basic_string_ref2((BString2&)other, 0, other.length());
        }
    }
    return *this;
}
