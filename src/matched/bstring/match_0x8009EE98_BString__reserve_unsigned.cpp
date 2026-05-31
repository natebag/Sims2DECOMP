// 0x8009EE98 BString::reserve(unsigned int) (152 B)
// FLAGS: -fno-schedule-insns
//
// Grows the backing rep to hold at least n characters. Throws on the npos
// sentinel; only reallocates when n+1 exceeds the current capacity. The new
// rep is copy-built from the existing data, then the old ref is dropped.

struct EAHeap {
    void* Malloc(unsigned int size, int flags);
};
extern EAHeap* MainHeap();

extern void basic_string_ref__throwlength();

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
    char*        data() const;
    unsigned int length() const;
    unsigned int reserve() const;
    void         delete_ref();
    void         reserve(unsigned int n);
};

void BString::reserve(unsigned int n)
{
    if (n == (unsigned int)-1)
        basic_string_ref__throwlength();

    if (n + 1 > reserve()) {
        basic_string_ref* rep = new basic_string_ref(data(), length(), n);
        delete_ref();
        m_rep = rep;
    }
}
