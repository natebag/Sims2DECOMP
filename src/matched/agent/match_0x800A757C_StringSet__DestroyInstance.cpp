// 0x800A757C (64 bytes)
// StringSet::DestroyInstance(StringSet *)
struct StringSet_vtable {
    char pad[0x60];
    short m_dtorThisOffset;  // 0x60
    char pad2[2];
    void* m_dtorFn;          // 0x64
};

struct StringSet {
    void** _vtable;   // 0x00
    int m_field_04;   // 0x04
    void* m_string;   // 0x08
    void* m_pDB;      // 0x0C
    int m_field_10;   // 0x10

    static void DestroyInstance(StringSet* ptr);
};

void StringSet::DestroyInstance(StringSet* ptr) {
    if (ptr != 0) {
        StringSet_vtable* vt = (StringSet_vtable*)ptr->_vtable;
        short offset = vt->m_dtorThisOffset;
        void (*fn)(void*, int) = (void (*)(void*, int))vt->m_dtorFn;
        fn((char*)ptr + offset, 3);
    }
}
