// 0x80295930 AptDate::sMethod_setHours(AptValue*, int) (256B) — clean
//
// AptScript native handler: AptDate.setHours(h). With no argument, returns the
// cached "undefined" value. Otherwise pops the top argument off the AptScript
// argument stack, coerces it to an integer, stores it as the hours field (0x2C),
// recomputes the cached timestamps via setDates, then boxes 0 into a number
// AptValue via the inlined AptValueGC allocator (recycle off the GC free-list,
// else allocate fresh).

struct AptValue {
    int toInteger() const;   // @0x802B04B8
};

struct AptSysClock;

struct AptArgStack {
    int        count;        // 0x00
    int        field4;       // 0x04
    AptValue** data;         // 0x08
};

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

extern AptArgStack   g_aptArgStack;        // absolute (base 0x8049C160)
extern AptValue*     g_aptDateUTCResult;   // SDA -0x5998
extern AptNum*       g_aptGCFreeList;       // SDA -0x691c
extern AptGCVector*  g_aptGCVector;         // SDA -0x6bd0
extern AptValuePool* g_aptValuePool;        // SDA -0x59ec
extern void*         g_aptNumberVTable[];   // absolute number-value vtable

struct AptDate {
    void setDates(AptSysClock* a, AptSysClock* b, int n);   // @0x802942A8
    static AptValue* sMethod_setHours(AptDate* self, int argc);
};

AptValue* AptDate::sMethod_setHours(AptDate* self, int argc) {
    if (argc <= 0) {
        return g_aptDateUTCResult;
    }
    int count = g_aptArgStack.count;
    AptValue* arg = g_aptArgStack.data[count - 1];
    *(int*)((char*)self + 0x2C) = arg->toInteger();
    self->setDates((AptSysClock*)((char*)self + 36),
                   (AptSysClock*)((char*)self + 68),
                   *(int*)((char*)self + 0x64));
    int value = 0;
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
