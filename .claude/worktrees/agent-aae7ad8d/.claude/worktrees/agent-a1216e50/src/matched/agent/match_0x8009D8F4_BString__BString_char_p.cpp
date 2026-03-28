/* 0x8009D8F4 (76 bytes) - BString::BString(char *) */

typedef unsigned int size_t;

class EAHeap {
public:
    void *Malloc(size_t size, int align);
};

class basic_string_ref {
public:
    basic_string_ref(char *str);
};

EAHeap *MainHeap(void);

inline void *operator new(size_t, void *p) { return p; }

class BString {
public:
    basic_string_ref *m_ref;

    BString(char *str);
};

BString::BString(char *str)
{
    EAHeap *heap = MainHeap();
    void *mem = heap->Malloc(16, 0);
    m_ref = new (mem) basic_string_ref(str);
}
