// 0x8028729C AptArray::sMethod_unshift(AptValue*, int) (372B) — clean
//
// AptScript array unshift: reserves room, shifts the existing elements up by the
// argument count, then writes the pushed arguments (top-down off the arg stack)
// into the freed front slots via set(); returns the new element count boxed as a
// number AptValue. Undefined for non-arrays.

struct AptValue;
extern AptValue* gpAptUndefined;   // SDA -0x5998

struct AptArgStack { int count; int pad4; AptValue** data; };
extern AptArgStack g_aptArgStack;  // absolute @0x8049C160

extern "C" void* memmove(void* dst, const void* src, unsigned int n);  // @0x802434F8

struct AptNum {
    unsigned w0; unsigned w4; void* w8; int w12;
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
    char         pad[0x20]; // 0x04 .. 0x23
    AptValue**   m_data;    // 0x24
    int          m_capacity;// 0x28
    int          m_count;   // 0x2C
    void _reserve(int n);                  // @0x80285F30
    void set(int index, AptValue* value);  // @0x80285FEC
    static AptValue* sMethod_unshift(AptArray* self, int argc);
};

AptValue* AptArray::sMethod_unshift(AptArray* self, int argc) {
    unsigned int flags = self->m_flags;
    int valid = 0;
    if ((flags & 0x7Fu) == 22) {
        valid = (flags >> 27) & 1;
    }
    if (valid) {
        self->_reserve(self->m_count + argc);
        if (argc != 0) {
            memmove(self->m_data + argc, self->m_data, self->m_count * 4);
            self->m_count = self->m_count + argc;
            for (int i = 0; i < argc; i++) {
                self->m_data[i] = 0;
                int count = g_aptArgStack.count;
                AptValue* value = g_aptArgStack.data[count - i - 1];
                self->set(i, value);
            }
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
