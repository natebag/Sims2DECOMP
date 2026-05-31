// 0x8009D9D4 BString::operator=(BString&) (152 B)
// FLAGS: -fno-schedule-insns
//
// Whole-string copy assignment. Self-assign guard; drop our current ref; then
// either share the source rep (refcount bump) when it is shareable
// (ref_count() != -1), or deep-copy into a freshly allocated rep otherwise.

struct BString;

struct EAHeap {
    void* Malloc(unsigned int size, int flags);
};
extern EAHeap* MainHeap();

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
    int  length() const;
    int  ref_count() const;
    void delete_ref();
    BString& operator=(const BString& other);
};

BString& BString::operator=(const BString& other)
{
    if (this != &other) {
        delete_ref();
        if (other.ref_count() != -1) {
            m_rep = other.m_rep;
            ++m_rep->m_ref_count;
        } else {
            m_rep = new basic_string_ref((BString&)other, 0, other.length());
        }
    }
    return *this;
}
