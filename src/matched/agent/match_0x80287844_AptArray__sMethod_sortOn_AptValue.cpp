// 0x80287844 AptArray::sMethod_sortOn(AptValue*, int) (212B) — clean
//
// AptScript array sortOn: stringifies the (top-of-stack) sort key into the global
// sort-key string, qsorts the slots with the "sort-on" comparator, then releases
// that global string (inline refcount drop + pool free) and resets it to the
// shared empty buffer. Undefined for non-arrays or when no key is supplied.

struct EAStringC { char* m_ptr; };
extern char* g_sortOnKey;              // SDA -0x59C4 (the sort-key string's buffer pointer)
extern char EAStringC_sEmptyString[];  // shared empty-string buffer

struct AptValue;
extern AptValue* gpAptUndefined;       // SDA -0x5998

struct AptArgStack { int count; int pad4; AptValue** data; };
extern AptArgStack g_aptArgStack;      // absolute @0x8049C160

struct AptValuePool { void Deallocate(void* p, unsigned int size); };  // @0x802B598C
extern AptValuePool* g_aptValuePool;   // SDA -0x59ec

extern "C" void qsort(void* base, int nmemb, int size, void* compar);  // @0x80242918
extern "C" int  defaultSortOnCompareFunc();                            // @0x802876F4

struct AptValueT { void toString(EAStringC& out) const; };             // AptValue::toString @0x802B08BC

struct AptArray {
    unsigned int m_flags;   // 0x00
    char         pad[0x20]; // 0x04 .. 0x23
    AptValueT**  m_data;    // 0x24
    int          m_capacity;// 0x28
    int          m_count;   // 0x2C
    static AptValue* sMethod_sortOn(AptArray* self, int argc);
};

AptValue* AptArray::sMethod_sortOn(AptArray* self, int argc) {
    unsigned int flags = self->m_flags;
    int valid = 0;
    if ((flags & 0x7Fu) == 22) {
        valid = (flags >> 27) & 1;
    }
    if (valid && argc > 0) {
        AptValueT* key = (AptValueT*)g_aptArgStack.data[g_aptArgStack.count - 1];
        key->toString(*(EAStringC*)&g_sortOnKey);
        qsort(self->m_data, self->m_count, 4, (void*)defaultSortOnCompareFunc);

        char* p = g_sortOnKey;
        unsigned short* h = (unsigned short*)p;
        unsigned int dec = (unsigned int)h[0] - 1;
        unsigned short masked = (unsigned short)dec;
        h[0] = (unsigned short)dec;
        if (masked == 0) {
            g_aptValuePool->Deallocate(p, *(unsigned short*)(p + 4) + 9);
        }
        g_sortOnKey = EAStringC_sEmptyString;
        ++*(unsigned short*)EAStringC_sEmptyString;
    }
    return gpAptUndefined;
}
