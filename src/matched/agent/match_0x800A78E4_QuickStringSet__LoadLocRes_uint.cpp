// 0x800A78E4 (88 bytes)
// QuickStringSet::LoadLocRes(unsigned int, short)
struct ResFile {};

struct Singleton_vtable {
    char pad[0x38];
    short m_getResFileThisOffset;  // 0x38
    char pad2[2];
    void* m_getResFileFn;          // 0x3C
};

struct Singleton {
    void** _vtable;
};

extern Singleton* g_singleton;

struct QuickStringSet {
    void** _vtable;   // 0x00
    void* m_field_04; // 0x04
    void* m_string;   // 0x08
    void* m_pDB;      // 0x0C
    int m_field_10;   // 0x10

    void LoadLocRes(unsigned int id, short flags);
    void LoadLocRes(ResFile* rf, short flags);
};

void QuickStringSet::LoadLocRes(unsigned int id, short flags) {
    Singleton* s = g_singleton;
    Singleton_vtable* vt = (Singleton_vtable*)s->_vtable;
    short offset = vt->m_getResFileThisOffset;
    ResFile* (*fn)(void*) = (ResFile* (*)(void*))vt->m_getResFileFn;
    ResFile* rf = fn((char*)s + offset);
    LoadLocRes(rf, flags);
}
