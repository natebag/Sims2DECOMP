// 0x8029562C AptDate::sMethod_getYear(AptValue*, int) (180B) — clean
//
// AptScript native handler: boxes (year - 1900) into a number AptValue (JS
// Date.getYear semantics). The computed value lands in the callee-saved value
// register; the boxing is the inlined AptValueGC allocator (recycle off the GC
// free-list, else allocate a fresh AptValue(7) from the value pool).

struct AptValue;

struct AptNum {
    unsigned w0;     // 0x00 flags; bit 0x20000000 = "registered in GC vector"
    unsigned w4;     // 0x04
    void*    w8;     // 0x08 vtable
    int      w12;    // 0x0C boxed value / free-list next link
    void initType(int vftIdx);   // AptValue::AptValue(VFT_Indices) @0x802B45FC
};

struct AptGCVector {
    int    cap;      // 0x00
    int    size;     // 0x04
    void** data;     // 0x08
};

struct AptValuePool {
    void* Allocate(unsigned int size);   // @0x802B5848
};

struct AptDateObj {
    char pad[0x3C];
    int  m_year;     // 0x3C
};

extern AptNum*       g_aptGCFreeList;       // SDA -0x691c
extern AptGCVector*  g_aptGCVector;         // SDA -0x6bd0
extern AptValuePool* g_aptValuePool;        // SDA -0x59ec
extern void*         g_aptNumberVTable[];   // absolute number-value vtable

struct AptDate {
    static AptValue* sMethod_getYear(AptDateObj* self, int argc);
};

AptValue* AptDate::sMethod_getYear(AptDateObj* self, int argc) {
    int value = self->m_year - 1900;
    AptNum* head = g_aptGCFreeList;
    if (head != 0) {
        unsigned w0 = head->w0;
        AptNum* next = (AptNum*)head->w12;
        AptGCVector* vec = g_aptGCVector;
        unsigned marked = w0 | 0x20000000u;
        g_aptGCFreeList = next;
        head->w0 = marked;
        int size = vec->size;
        int cap = vec->cap;
        if (size >= cap) {
            head->w0 = marked & ~0x20000000u;
        } else {
            vec->data[size] = head;
            vec->size = size + 1;
        }
        head->w12 = value;
        return (AptValue*)head;
    }
    AptNum* obj = (AptNum*)g_aptValuePool->Allocate(16);
    obj->initType(7);
    obj->w12 = value;
    obj->w8 = (void*)g_aptNumberVTable;
    return (AptValue*)obj;
}
