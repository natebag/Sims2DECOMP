/* 0x8009D940 (84 bytes) - BString::BString(char, unsigned int) */

typedef unsigned int size_t;

class EAHeap {
public:
    void *Malloc(size_t size, int align);
};

class basic_string_ref {
public:
    basic_string_ref(char c, unsigned int count);
};

EAHeap *MainHeap(void);

inline void *operator new(size_t, void *p) { return p; }

class BString {
public:
    basic_string_ref *m_ref;

    BString(char c, unsigned int count);
};

BString::BString(char c, unsigned int count)
{
    EAHeap *heap = MainHeap();
    void *mem = heap->Malloc(16, 0);
    m_ref = new (mem) basic_string_ref(c, count);
}
