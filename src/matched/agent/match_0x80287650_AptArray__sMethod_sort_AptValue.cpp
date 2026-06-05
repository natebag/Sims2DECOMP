// 0x80287650 AptArray::sMethod_sort(AptValue*, int) (164B) — clean
//
// AptScript array sort handler. Same typed-array guard as the rest of the family.
// With no argument, qsorts the slots with the default comparator. With an argument
// it pulls the script comparator value off the top of the arg stack, stashes it
// (and one of its fields) in the sort-context globals, and qsorts with the script
// comparator trampoline. Always returns the undefined sentinel.

struct AptValue;
extern AptValue* gpAptUndefined;   // SDA -0x5998

struct AptArgStack { int count; int pad4; AptValue** data; };
extern AptArgStack g_aptArgStack;  // absolute @0x8049C160

extern AptValue* g_sortCmpValue;   // SDA -0x6b94
extern void*     g_sortCmpField;   // SDA -0x6b90

extern "C" void qsort(void* base, int nmemb, int size, void* compar);  // @0x80242918
extern "C" int  defaultSortCompareFunc();                              // @0x80287410
extern "C" int  scriptFunctionSortFunc();                              // @0x802874E0

struct AptArray {
    unsigned int m_flags;   // 0x00
    char         pad[0x20]; // 0x04 .. 0x23
    AptValue**   m_data;    // 0x24
    int          m_capacity;// 0x28
    int          m_count;   // 0x2C
    static AptValue* sMethod_sort(AptArray* self, int argc);
};

AptValue* AptArray::sMethod_sort(AptArray* self, int argc) {
    unsigned int flags = self->m_flags;
    int valid = 0;
    if ((flags & 0x7Fu) == 22) {
        valid = (flags >> 27) & 1;
    }
    if (valid) {
        if (argc == 0) {
            qsort(self->m_data, self->m_count, 4, (void*)defaultSortCompareFunc);
        } else {
            AptValue* cmp = g_aptArgStack.data[g_aptArgStack.count - 1];
            void* field = *(void**)((char*)cmp + 36);
            g_sortCmpValue = cmp;
            g_sortCmpField = field;
            qsort(self->m_data, self->m_count, 4, (void*)scriptFunctionSortFunc);
        }
    }
    return gpAptUndefined;
}
