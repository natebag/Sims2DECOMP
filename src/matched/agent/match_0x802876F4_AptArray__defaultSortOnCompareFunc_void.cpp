// 0x802876F4 AptArray::defaultSortOnCompareFunc(void*, void*) (336B) — clean
//
// qsort "sortOn" comparator. Resolves the configured sort key (global g_sortOnKey)
// inside each of the two values, then defers to defaultSortCompareFunc:
//   - if both are objects (type 27, resizable): look the key up in each object's
//     native hash (member @+12) and compare the looked-up values;
//   - else if both are arrays (type 22, resizable): atoi() the key into an index and
//     compare the elements at that index;
//   - otherwise 0.

struct EAStringC { char* m_ptr; };
extern char* g_sortOnKey;                                   // SDA -0x59c4 (sort-key string buffer)

struct AptValue;
struct AptNativeHash { AptValue* Lookup(EAStringC* key) const; };  // @0x802A9F9C

struct AptArray {
    unsigned int m_flags;                                   // 0
    AptValue* get(int index) const;                         // @0x802860AC
    static int defaultSortCompareFunc(void* pa, void* pb);  // @0x80287410
    static int defaultSortOnCompareFunc(void* pa, void* pb);
};
extern "C" int atoi(const char* s);                         // @0x8036E510

int AptArray::defaultSortOnCompareFunc(void* pa, void* pb) {
    AptArray* a = *(AptArray**)pa;
    AptArray* b = *(AptArray**)pb;

    unsigned int fa = a->m_flags;
    int va = 0;
    if ((fa & 0x7Fu) == 27) va = (fa >> 27) & 1;
    if (va) {
        unsigned int fb = b->m_flags;
        int vb = 0;
        if ((fb & 0x7Fu) == 27) vb = (fb >> 27) & 1;
        if (vb) {
            AptValue* x = 0;
            AptValue* y = 0;
            x = ((AptNativeHash*)((char*)a + 12))->Lookup((EAStringC*)&g_sortOnKey);
            if (x) {
                y = ((AptNativeHash*)((char*)b + 12))->Lookup((EAStringC*)&g_sortOnKey);
                if (y)
                    return defaultSortCompareFunc(&x, &y);
            }
            return 0;
        }
    }

    unsigned int fa2 = a->m_flags;
    int va2 = 0;
    if ((fa2 & 0x7Fu) == 22) va2 = (fa2 >> 27) & 1;
    if (va2) {
        unsigned int fb2 = b->m_flags;
        int vb2 = 0;
        if ((fb2 & 0x7Fu) == 22) vb2 = (fb2 >> 27) & 1;
        if (vb2) {
            AptValue* x2 = 0;
            AptValue* y2 = 0;
            x2 = a->get(atoi(g_sortOnKey + 8));
            y2 = b->get(atoi(g_sortOnKey + 8));
            return defaultSortCompareFunc(&x2, &y2);
        }
    }
    return 0;
}
