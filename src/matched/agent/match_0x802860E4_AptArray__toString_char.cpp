// 0x802860E4 AptArray::toString(char*, char*) (132B) — clean
//
// char-buffer convenience overload of AptArray::toString: builds a temp EAStringC,
// delegates to the EAStringC worker overload (@0x80286168), copies the resulting
// characters into the caller's buffer, then releases the temp (inline refcount
// drop + pool free). Returns void; the format arg passes straight through to the
// worker. The 8-byte string handle lands in the 8-aligned compiler-temp slot
// (str @ sp+8). Default instruction scheduling reproduces the worker-arg /
// ctor-store ordering.

struct EAStringC { char* m_ptr; int m_pad; };   // 8-byte string-COW handle
extern char EAStringC_sEmptyString[];            // shared empty-string buffer [u16 ref, u16 cap, chars...]

struct AptValuePool { void Deallocate(void* p, unsigned int size); };  // @0x802B598C
extern AptValuePool* g_aptValuePool;             // SDA -0x59ec

extern "C" char* strcpy(char* dst, const char* src);                   // @0x802438E0

struct AptArray {
    void toString(EAStringC& out, char* fmt);    // worker @0x80286168
    void toString(char* dest, char* fmt);
};

void AptArray::toString(char* dest, char* fmt) {
    EAStringC str;
    unsigned short rc = *(unsigned short*)EAStringC_sEmptyString;
    str.m_ptr = EAStringC_sEmptyString;
    *(unsigned short*)EAStringC_sEmptyString = (unsigned short)(rc + 1);

    toString(str, fmt);
    strcpy(dest, str.m_ptr + 8);

    {   // ~EAStringC str
        char* p = str.m_ptr;
        unsigned short* h = (unsigned short*)p;
        unsigned int dec = (unsigned int)h[0] - 1;
        unsigned short masked = (unsigned short)dec;
        h[0] = (unsigned short)dec;
        if (masked == 0)
            g_aptValuePool->Deallocate(p, *(unsigned short*)(p + 4) + 9);
    }
}
