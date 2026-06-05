// 0x80285A2C (124B) AptArray::AptArray(void)
//
// AptArray : AptValueWithHash : AptValue. The AptValueWithHash base ctor is
// inlined (AptValue ctor with vft index 22 via external bl, AptValueWithHash
// vtable @0x08, embedded AptNativeHash @0x0C constructed from 8 via external
// bl). AptArray then installs its own vtable @0x08, initialises the state word
// @0x20 (top byte zero + bits 8,9 clear), and zeroes its three array fields
// @0x24/0x28/0x2C. Clean structural C++; default scheduling.

struct AptValue {
    unsigned int m_flags;    // 0x00
    unsigned int m_field04;  // 0x04
    virtual void dummy();    // vptr @ 0x08 (SN: after the 2 head data words)
    AptValue(int vftIdx);    // external -> bl
};

struct AptNativeHash {
    unsigned int m_capacity; // 0x00
    unsigned int m_4;        // 0x04
    unsigned int m_8;        // 0x08
    unsigned int m_12;       // 0x0C
    unsigned int m_16;       // 0x10
    AptNativeHash(int n);    // external -> bl
};

struct AptValueWithHash : public AptValue {
    AptNativeHash m_hash;    // 0x0C .. 0x20
    AptValueWithHash(int vftIdx, int arg)
        : AptValue(vftIdx), m_hash(arg) {}   // inlined base ctor
    virtual void dummy();    // override -> distinct vtable
};

struct AptArray : public AptValueWithHash {
    union {
        unsigned char m_state_byte;  // 0x20 (big-endian top byte)
        unsigned int  m_state_word;  // 0x20 full state word
    };
    unsigned int m_data;     // 0x24
    unsigned int m_28;       // 0x28
    unsigned int m_count;    // 0x2C
    AptArray();
    virtual void dummy();    // override -> distinct vtable @0x80403FE0
};

AptArray::AptArray()
    : AptValueWithHash(22, 8)
{
    m_state_byte = 0;
    m_state_word &= ~0x00C00000u;
    // store order: default scheduler hoists the last field-store (m_count @0x2C)
    // to the front, then emits the rest in source order (m_28 @0x28, m_data
    // @0x24) -> DOL order 0x2C, 0x28, [0x20], 0x24.
    m_28 = 0;
    m_data = 0;
    m_count = 0;
}
