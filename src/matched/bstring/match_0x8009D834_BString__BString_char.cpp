// 0x8009D834 BString::BString(char*, unsigned int, unsigned int) (104 B)
// FLAGS:
//
// Construct from a C-string slice [pos, pos+n). Overflow-guards pos+n against
// the npos sentinel, then deep-copies into a fresh rep (delegates to the
// char*-range rep ctor via external bl, so dodges the allocator-wall).

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
    basic_string_ref(char* s, unsigned int from, unsigned int to);
    void* operator new(unsigned int n) { return MainHeap()->Malloc(n, 0); }
};

struct BString {
    basic_string_ref* m_rep;
    BString(char* s, unsigned int pos, unsigned int n);
};

BString::BString(char* s, unsigned int pos, unsigned int n)
{
    if (pos >= ~n)
        basic_string_ref__throwlength();
    m_rep = new basic_string_ref(s, pos, pos + n);
}
