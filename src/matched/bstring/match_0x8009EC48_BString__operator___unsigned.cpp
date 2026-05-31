// 0x8009EC48 BString::operator[](unsigned int) (176 B)
// FLAGS:
//
// Mutable element access. Range-checks the index, detaches a shared rep
// (copy-on-write) so the caller can write through the returned reference, then
// returns a reference into the writable buffer.

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
    basic_string_ref(char* s, unsigned int len, unsigned int cap);
    void* operator new(unsigned int n) { return MainHeap()->Malloc(n, 0); }
};

struct BString {
    basic_string_ref* m_rep;
    unsigned int length() const;
    unsigned int ref_count() const;
    char*        data() const;
    char*        point();
    void         delete_ref();
    char&        operator[](unsigned int i);
};

char& BString::operator[](unsigned int i)
{
    if (i >= length())
        basic_string_ref__throwrange();
    if (ref_count() > 1) {
        basic_string_ref* rep = new basic_string_ref(data(), length(), length());
        delete_ref();
        m_rep = rep;
    }
    return point()[i];
}
