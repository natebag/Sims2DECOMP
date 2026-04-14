/* 0x800A1CD0 (76 bytes) - BString2::BString2(unsigned wchar_t *) */

typedef unsigned int size_t;
typedef unsigned short wchar_t_ea;

class EAHeap {
public:
    void *Malloc(size_t size, int align);
};

class basic_string_ref2 {
public:
    basic_string_ref2(wchar_t_ea *str);
};

EAHeap *MainHeap(void);

inline void *operator new(size_t, void *p) { return p; }

class BString2 {
public:
    basic_string_ref2 *m_ref;

    BString2(wchar_t_ea *str);
};

BString2::BString2(wchar_t_ea *str)
{
    EAHeap *heap = MainHeap();
    void *mem = heap->Malloc(16, 0);
    m_ref = new (mem) basic_string_ref2(str);
}
