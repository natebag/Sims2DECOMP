// 0x802870D4 AptArray::sMethod_push(AptValue*, int) (292B) — clean
//
// AptScript array push: appends each pushed argument (taken top-down off the arg
// stack) to the array via set(), then boxes and returns the new element count as a
// number AptValue (inlined AptValueGC number allocator). Undefined for non-arrays.

struct AptValue;
extern AptValue* gpAptUndefined;   // SDA -0x5998

struct AptArgStack { int count; int pad4; AptValue** data; };
extern AptArgStack g_aptArgStack;  // absolute @0x8049C160

struct AptNum {
    unsigned w0;     // 0x00 flags
    unsigned w4;     // 0x04
    void*    w8;     // 0x08 vtable
    int      w12;    // 0x0C boxed value / free-list next
    void initType(int vftIdx);   // AptValue::AptValue(7) @0x802B45FC
};
struct AptGCVector { int cap; int size; void** data; };
struct AptValuePool { void* Allocate(unsigned int size); };   // @0x802B5848

extern AptNum*       g_aptGCFreeList;     // SDA -0x691c
extern AptGCVector*  g_aptGCVector;       // SDA -0x6bd0
extern AptValuePool* g_aptValuePool;      // SDA -0x59ec
extern void*         g_aptNumberVTable[]; // absolute number-value vtable

struct AptArray {
    unsigned int m_flags;   // 0x00
    char         pad[0x28]; // 0x04 .. 0x2B
    int          m_count;   // 0x2C
    void set(int index, AptValue* value);                       // @0x80285FEC
    static AptValue* sMethod_push(AptArray* self, int argc);
};

AptValue* AptArray::sMethod_push(AptArray* self, int argc) {
    unsigned int flags = self->m_flags;
    int valid = 0;
    if ((flags & 0x7Fu) == 22) {
        valid = (flags >> 27) & 1;
    }
    if (valid) {
        for (int i = 0; i < argc; i++) {
            int count = g_aptArgStack.count;
            AptValue* value = g_aptArgStack.data[count - i - 1];
            self->set(self->m_count, value);
        }

        AptNum* head = g_aptGCFreeList;
        int value = self->m_count;
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
    return gpAptUndefined;
}
