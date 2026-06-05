// 0x802871F8 AptArray::sMethod_shift(AptValue*, int) (164B) — clean
//
// AptScript native handler: removes and returns the first element of a resizable
// array. Same typed-array guard as sMethod_pop; on success returns element 0,
// memmoves the remaining elements down one slot, shrinks the count, and nulls the
// vacated tail slot.

struct AptValue;
extern AptValue* gpAptUndefined;   // SDA -0x5998
extern "C" void* memmove(void* dst, const void* src, unsigned int n);  // @0x802434F8

struct AptArray {
    unsigned int m_flags;   // 0x00
    char         pad[0x20]; // 0x04 .. 0x23
    AptValue**   m_data;    // 0x24
    int          m_capacity;// 0x28
    int          m_count;   // 0x2C
    AptValue* get(int index) const;                       // @0x802860AC
    static AptValue* sMethod_shift(AptArray* self, int argc);
};

AptValue* AptArray::sMethod_shift(AptArray* self, int argc) {
    AptValue* result = gpAptUndefined;
    unsigned int flags = self->m_flags;
    int valid = 0;
    if ((flags & 0x7Fu) == 22) {
        valid = (flags >> 27) & 1;
    }
    if (valid) {
        int len = self->m_count;
        if (len > 0) {
            result = self->get(0);
            int newlen = self->m_count - 1;
            self->m_count = newlen;
            if (newlen != 0) {
                memmove(self->m_data, self->m_data + 1, newlen * 4);
            }
            self->m_data[self->m_count] = 0;
        }
    }
    return result;
}
