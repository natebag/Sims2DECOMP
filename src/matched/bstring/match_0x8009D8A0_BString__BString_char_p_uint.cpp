/* 0x8009D8A0 (84 bytes) - BString::BString(char *, unsigned int) */

typedef unsigned int size_t;

class EAHeap {
public:
    void *Malloc(size_t size, int align);
};

class basic_string_ref {
public:
    basic_string_ref(char *str, unsigned int len);
};

EAHeap *MainHeap(void);

inline void *operator new(size_t, void *p) { return p; }

class BString {
public:
    basic_string_ref *m_ref;

    BString(char *str, unsigned int len);
};

BString::BString(char *str, unsigned int len)
{
    EAHeap *heap = MainHeap();
    void *mem = heap->Malloc(16, 0);
    m_ref = new (mem) basic_string_ref(str, len);
}
