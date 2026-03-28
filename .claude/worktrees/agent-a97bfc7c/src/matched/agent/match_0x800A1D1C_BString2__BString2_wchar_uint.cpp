/* 0x800A1D1C (84 bytes) - BString2::BString2(wchar_t, unsigned int) */

typedef unsigned int size_t;
typedef short wchar_t_sn;

class EAHeap {
public:
    void *Malloc(size_t size, int align);
};

class basic_string_ref2 {
public:
    basic_string_ref2(wchar_t_sn c, unsigned int count);
};

EAHeap *MainHeap(void);

inline void *operator new(size_t, void *p) { return p; }

class BString2 {
public:
    basic_string_ref2 *m_ref;

    BString2(wchar_t_sn c, unsigned int count);
};

BString2::BString2(wchar_t_sn c, unsigned int count)
{
    EAHeap *heap = MainHeap();
    void *mem = heap->Malloc(16, 0);
    m_ref = new (mem) basic_string_ref2(c, count);
}
