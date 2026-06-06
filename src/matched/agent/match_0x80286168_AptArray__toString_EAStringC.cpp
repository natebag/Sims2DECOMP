// 0x80286168 AptArray::toString(EAStringC&, char*) (352B) — clean
//
// Array stringify worker: out = <initial literal>; then for each element, append
// its toString() and a separator between elements:
//   out = EAStringC(kInit);
//   for (i = 0; i < m_count; i++) {
//       if (m_data[i]) { EAStringC t; m_data[i]->toString(t); out += t; }
//       if (i < m_count - 1) out += sep;
//   }
// The COW copy-assign and all temp destructors are inlined (refcount drop +
// conditional pool free); operator+= / toString / InitFromBuffer are real calls.
// A single 8-byte temp string handle is reused (slot sp+8).

struct EAStringC {
    char* m_ptr;
    int   m_pad;
    void       InitFromBuffer(char* buf);     // @0x802BE7B0
    EAStringC& operator+=(EAStringC& s);       // @0x802BC3D4
    EAStringC& operator+=(char* s);            // @0x802BC5C4
};
extern char EAStringC_sEmptyString[];          // shared empty-string buffer
extern char kAptArrayToStringInit[];           // initial literal @0x80403B38

struct AptValuePool { void Deallocate(void* p, unsigned int size); };  // @0x802B598C
extern AptValuePool* g_aptValuePool;           // SDA -0x59ec

struct AptValueT { void toString(EAStringC& out) const; };             // AptValue::toString @0x802B08BC

struct AptArray {
    unsigned int m_flags;   // 0x00
    char         pad[0x20]; // 0x04..0x23
    AptValueT**  m_data;    // 0x24
    int          m_capacity;// 0x28
    int          m_count;   // 0x2C
    void toString(EAStringC& out, char* sep);
};

void AptArray::toString(EAStringC& out, char* sep) {
    EAStringC tmp;
    tmp.InitFromBuffer(kAptArrayToStringInit);

    // out = tmp   (inlined COW copy-assign)
    ++*(unsigned short*)tmp.m_ptr;
    {   // out.release()
        char* p = out.m_ptr;
        unsigned short* h = (unsigned short*)p;
        unsigned int dec = (unsigned int)h[0] - 1;
        unsigned short masked = (unsigned short)dec;
        h[0] = (unsigned short)dec;
        if (masked == 0)
            g_aptValuePool->Deallocate(p, *(unsigned short*)(p + 4) + 9);
    }
    out.m_ptr = tmp.m_ptr;
    {   // ~tmp
        char* p = tmp.m_ptr;
        unsigned short* h = (unsigned short*)p;
        unsigned int dec = (unsigned int)h[0] - 1;
        unsigned short masked = (unsigned short)dec;
        h[0] = (unsigned short)dec;
        if (masked == 0)
            g_aptValuePool->Deallocate(p, *(unsigned short*)(p + 4) + 9);
    }

    for (int i = 0; i < m_count; i++) {
        AptValueT* e = m_data[i];
        if (e) {
            tmp.m_ptr = EAStringC_sEmptyString;
            ++*(unsigned short*)EAStringC_sEmptyString;
            e->toString(tmp);
            out += tmp;
            {   // ~tmp
                char* p = tmp.m_ptr;
                unsigned short* h = (unsigned short*)p;
                unsigned int dec = (unsigned int)h[0] - 1;
                unsigned short masked = (unsigned short)dec;
                h[0] = (unsigned short)dec;
                if (masked == 0)
                    g_aptValuePool->Deallocate(p, *(unsigned short*)(p + 4) + 9);
            }
        }
        if (i < m_count - 1)
            out += sep;
    }
}
