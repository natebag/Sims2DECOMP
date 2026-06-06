// 0x80286D08 AptArray::sMethod_concat(AptValue*, int) (344B) — clean
//
// AScript Array.concat: returns a new array = this array followed by each argument
// (arrays are flattened one level, non-arrays appended as-is). Undefined if `this`
// is not a resizable array. The valid path is the fall-through body; the undefined
// return is the out-of-line tail (if-true layout).

struct AptValue;
struct AptArray {
    unsigned int m_flags;   // 0
    char         pad[0x20]; // 4..0x23
    AptValue**   m_data;    // 0x24
    int          m_capacity;// 0x28
    int          m_count;   // 0x2c
    void set(int index, AptValue* value);                 // @0x80285FEC
    AptArray();                                            // @0x80285A2C
    static AptValue* sMethod_concat(AptValue* self, int argc);
};

struct AptValueGCPool { void* AllocateAptValueGC(unsigned int size); };  // @0x802B512C
extern AptValueGCPool* g_aptValueGCPool;   // SDA -0x59e8

struct AptArgStack { int count; int pad4; AptValue** data; };
extern AptArgStack g_aptArgStack;           // absolute @0x8049C160

extern AptValue* gpAptUndefined;            // SDA -0x5998

inline void* operator new(unsigned int, void* p) { return p; }

AptValue* AptArray::sMethod_concat(AptValue* self_, int argc) {
    AptArray* self = (AptArray*)self_;
    unsigned int flags = self->m_flags;
    int valid = 0;
    if ((flags & 0x7Fu) == 22) valid = (flags >> 27) & 1;
    if (valid) {
        AptArray* result = new (g_aptValueGCPool->AllocateAptValueGC(48)) AptArray();

        for (int i = 0; i < self->m_count; i++)
            result->set(result->m_count, self->m_data[i]);

        for (int k = 0; k < argc; ) {
            AptValue* arg = g_aptArgStack.data[g_aptArgStack.count - k - 1];
            unsigned int af = ((AptArray*)arg)->m_flags;
            int av = 0;
            if ((af & 0x7Fu) == 22) av = (af >> 27) & 1;
            if (av) {
                AptArray* aa = (AptArray*)arg;
                for (int m = 0; m < aa->m_count; m++)
                    result->set(result->m_count, aa->m_data[m]);
            } else {
                result->set(result->m_count, arg);
            }
            k = k + 1;
        }
        return (AptValue*)result;
    }
    return gpAptUndefined;
}
