/* 0x8009D718 (84 bytes) - BString::BString(unsigned int, BString::capacity) */

typedef unsigned int size_t;

class EAHeap {
public:
    void *Malloc(size_t size, int align);
};

class basic_string_ref {
public:
    basic_string_ref(unsigned int n, int c);
};

EAHeap *MainHeap(void);

inline void *operator new(size_t, void *p) { return p; }

class BString {
public:
    basic_string_ref *m_ref;

    BString(unsigned int n, int c);
};

BString::BString(unsigned int n, int c)
{
    EAHeap *heap = MainHeap();
    void *mem = heap->Malloc(16, 0);
    m_ref = new (mem) basic_string_ref(n, c);
}
