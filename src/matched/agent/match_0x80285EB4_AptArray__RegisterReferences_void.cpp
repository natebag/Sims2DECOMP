// 0x80285EB4 (124B) AptArray::RegisterReferences(void) const
//
// GC reference registration. First chains to the base AptObject version, then
// walks the array's m_data[] (m_data@0x24, m_count@0x2C, 4-byte pointer slots)
// and, for each non-null element, invokes the GC-register callback through a
// global function pointer (SN ProDG emits mtlr;blrl for a call via a typedef
// fn-ptr loaded from a global). The callback gets (this, element, &context).
// m_data and m_count are re-read each iteration because the callback is a memory
// clobber. Clean structural C++; default scheduling.

struct AptObject {
    char _pad[0x24];                  // AptValue + AptNativeHash + state word
    void RegisterReferences() const;  // base (bl 0x802B5E54)
};

struct AptArray : public AptObject {
    void** m_data;   // 0x24 (array of 4-byte pointer slots)
    int    m_28;     // 0x28
    int    m_count;  // 0x2C
    void RegisterReferences() const;
};

typedef void (*AptGcRegisterFn)(const AptArray* self, void* element, void* context);
extern AptGcRegisterFn gAptGcRegisterFn;   // SDA fn-ptr
extern char gAptGcRegisterContext[];       // 0x80403F30 context block

void AptArray::RegisterReferences() const {
    AptObject::RegisterReferences();
    for (int i = 0; i < m_count; ++i) {
        void* element = m_data[i];
        if (element != 0)
            gAptGcRegisterFn(this, element, (void*)gAptGcRegisterContext);
    }
}
