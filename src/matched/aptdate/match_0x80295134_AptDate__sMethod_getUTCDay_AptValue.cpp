// 0x80295134 AptDate::sMethod_getUTCDay(AptValue*, int) (192B) — clean
//
// AptScript native handler: computes the weekday from the UTC (year,month,day)
// fields (0x5C/0x58/0x54) via AptDate::getDayOfWeek and boxes the result into a
// number AptValue. The boxing is the inlined AptValueGC allocator (recycle off
// the GC free-list, else allocate fresh AptValue(7) from the value pool).

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

extern AptNum*       g_aptGCFreeList;       // SDA -0x691c
extern AptGCVector*  g_aptGCVector;         // SDA -0x6bd0
extern AptValuePool* g_aptValuePool;        // SDA -0x59ec
extern void*         g_aptNumberVTable[];   // absolute number-value vtable

struct AptDate {
    int  getDayOfWeek(int year, int month, int day);   // @0x802943E0
    static AptValue* sMethod_getUTCDay(AptDate* self, int argc);
};

struct AptDateObj {
    char pad[0x54];
    int  m_utcDay;     // 0x54
    int  m_utcMonth;   // 0x58
    int  m_utcYear;    // 0x5C
};

AptValue* AptDate::sMethod_getUTCDay(AptDate* self, int argc) {
    AptDateObj* d = (AptDateObj*)self;
    int value = self->getDayOfWeek(d->m_utcYear, d->m_utcMonth, d->m_utcDay);
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
