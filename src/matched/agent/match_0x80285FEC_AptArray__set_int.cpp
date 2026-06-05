// 0x80285FEC AptArray::set(int, AptValue*) (192B) — clean
//
// Stores a value at an array index (no-op for negative indices). Grows the store,
// GC-registers the incoming value, GC-releases whatever previously occupied the
// slot, writes the slot, and bumps the element count to cover the index. The
// register/release are tracked through the value's vtable (8-byte SN ABI entries,
// this-adjusting) with the call-site file/line descriptor globals.

struct AptValueData { unsigned int w0; unsigned int w4; };   // 8B before the vptr
struct AptValue : AptValueData {
    virtual void GCRegister(char* file, char* func, int line);   // vtable slot 1 (@8/@12)
    virtual void GCRelease(char* file, char* func, int line);    // vtable slot 2 (@16/@20)
};

extern char gGCDesc1[];   // absolute @0x80403A4C
extern char gGCDesc2[];   // absolute @0x80403A74

struct AptArray {
    char       pad[0x24];   // 0x00 .. 0x23
    AptValue** m_data;      // 0x24
    int        m_capacity;  // 0x28
    int        m_count;     // 0x2C
    void _reserve(int n);                        // @0x80285F30
    void set(int index, AptValue* value);
};

void AptArray::set(int index, AptValue* value) {
    if (index < 0) {
        return;
    }
    int newcount = index + 1;
    _reserve(newcount);
    AptValue* old = m_data[index];
    value->GCRegister(gGCDesc1, gGCDesc2, 284);
    if (old != 0) {
        old->GCRelease(gGCDesc1, gGCDesc2, 285);
    }
    m_data[index] = value;
    int c = m_count;
    if (c < newcount) {
        c = newcount;
    }
    m_count = c;
}
