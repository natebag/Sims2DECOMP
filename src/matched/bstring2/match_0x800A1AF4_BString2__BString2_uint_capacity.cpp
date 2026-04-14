/* 0x800A1AF4 (84 bytes) - BString2::BString2(unsigned int, BString2::capacity) */

typedef unsigned int size_t;

class EAHeap {
public:
    void *Malloc(size_t size, int align);
};

class basic_string_ref2 {
public:
    basic_string_ref2(unsigned int n, int c);
};

EAHeap *MainHeap(void);

inline void *operator new(size_t, void *p) { return p; }

class BString2 {
public:
    basic_string_ref2 *m_ref;

    BString2(unsigned int n, int c);
};

BString2::BString2(unsigned int n, int c)
{
    EAHeap *heap = MainHeap();
    void *mem = heap->Malloc(16, 0);
    m_ref = new (mem) basic_string_ref2(n, c);
}
