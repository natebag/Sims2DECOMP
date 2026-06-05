// 0x80287054 AptArray::sMethod_pop(AptValue*, int) (128B) — clean
//
// AptScript native handler: pops the last element off a resizable array. Returns
// the undefined sentinel unless self is an array value (low-7-bit type tag == 22)
// flagged resizable (flag bit 0x08000000) and non-empty; in that case returns the
// last element (via AptArray::get), shrinks the count, and nulls the vacated slot.

struct AptValue;
extern AptValue* gpAptUndefined;   // SDA -0x5998

struct AptArray {
    unsigned int m_flags;   // 0x00
    char         pad[0x20]; // 0x04 .. 0x23
    AptValue**   m_data;    // 0x24
    int          m_capacity;// 0x28
    int          m_count;   // 0x2C
    AptValue* get(int index) const;                     // @0x802860AC
    static AptValue* sMethod_pop(AptArray* self, int argc);
};

AptValue* AptArray::sMethod_pop(AptArray* self, int argc) {
    int valid = 0;
    unsigned int flags = self->m_flags;
    AptValue* result = gpAptUndefined;
    if ((flags & 0x7Fu) == 22) {
        valid = (flags >> 27) & 1;
    }
    if (valid) {
        int len = self->m_count;
        if (len > 0) {
            result = self->get(len - 1);
            int idx = self->m_count - 1;
            self->m_count = idx;
            self->m_data[idx] = 0;
        }
    }
    return result;
}
