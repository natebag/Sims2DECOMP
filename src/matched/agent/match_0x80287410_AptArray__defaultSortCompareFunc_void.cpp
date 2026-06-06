// FLAGS: -fno-schedule-insns
// 0x80287410 AptArray::defaultSortCompareFunc(void*, void*) (208B) — clean
//
// Default (lexical) qsort comparator for an AptScript array sort. Stringifies the
// two AptValues *a / *b into temp EAStringC buffers, strcmp's their characters,
// then releases both temp strings (inline refcount drop + pool free, in reverse
// construction order). Both temps default-construct to the shared empty buffer,
// so their two refcount bumps merge into a single +2. The two 8-byte string
// handles occupy the 8-aligned compiler-temp slots (s1 @ sp+8, s2 @ sp+0x10).

struct EAStringC { char* m_ptr; int m_pad; };  // 8-byte string-COW handle (only m_ptr used here)
extern char EAStringC_sEmptyString[];   // shared empty-string buffer [u16 ref, u16 cap, chars...]

struct AptValuePool { void Deallocate(void* p, unsigned int size); };  // @0x802B598C
extern AptValuePool* g_aptValuePool;    // SDA -0x59ec

struct AptValueT { void toString(EAStringC& out) const; };             // AptValue::toString @0x802B08BC

extern "C" int strcmp(const char* a, const char* b);                   // @0x80243838

struct AptArray {
    static int defaultSortCompareFunc(void* pa, void* pb);
};

int AptArray::defaultSortCompareFunc(void* pa, void* pb) {
    AptValueT* a = *(AptValueT**)pa;
    AptValueT* b = *(AptValueT**)pb;

    EAStringC s1, s2;
    unsigned short rc = *(unsigned short*)EAStringC_sEmptyString;
    s2.m_ptr = EAStringC_sEmptyString;
    *(unsigned short*)EAStringC_sEmptyString = (unsigned short)(rc + 2);
    s1.m_ptr = EAStringC_sEmptyString;

    a->toString(s1);
    b->toString(s2);

    int r = strcmp(s1.m_ptr + 8, s2.m_ptr + 8);

    {   // ~EAStringC s2
        char* p = s2.m_ptr;
        unsigned short* h = (unsigned short*)p;
        unsigned int dec = (unsigned int)h[0] - 1;
        unsigned short masked = (unsigned short)dec;
        h[0] = (unsigned short)dec;
        if (masked == 0)
            g_aptValuePool->Deallocate(p, *(unsigned short*)(p + 4) + 9);
    }
    {   // ~EAStringC s1
        char* p = s1.m_ptr;
        unsigned short* h = (unsigned short*)p;
        unsigned int dec = (unsigned int)h[0] - 1;
        unsigned short masked = (unsigned short)dec;
        h[0] = (unsigned short)dec;
        if (masked == 0)
            g_aptValuePool->Deallocate(p, *(unsigned short*)(p + 4) + 9);
    }
    return r;
}
