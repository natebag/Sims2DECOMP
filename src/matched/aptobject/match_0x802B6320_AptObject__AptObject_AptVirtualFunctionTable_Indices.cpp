// 0x802B6320 (108B) AptObject::AptObject(AptVirtualFunctionTable_Indices, int)
//
// Most-derived ctor for the APT object value type. The hierarchy is
// AptObject : AptValueWithHash : AptValue. The AptValueWithHash base ctor is
// inlined here: it runs AptValue's ctor (vft index, external bl), installs the
// AptValueWithHash vtable @0x08, and constructs the embedded AptNativeHash
// @0x0C from the int arg (external bl). AptObject then installs its own final
// vtable @0x08 and initialises its state word @0x20 -- zero the top byte and
// clear the two state bits 8,9 (& ~0x00C00000, i.e. rlwinm 0,10,7).
//
// Clean structural C++. Default scheduling reproduces the DOL's stb-before-vptr
// ordering: the byte store (r0=0, ready after one li) fills the slot while the
// vtable address is still being materialised (lis+addi).

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
    virtual void dummy();    // override -> distinct vtable @0x80412318
};

struct AptObject : public AptValueWithHash {
    union {
        unsigned char m_state_byte;  // 0x20 (big-endian top byte)
        unsigned int  m_state_word;  // 0x20 full state word
    };
    AptObject(int vftIdx, int arg);
    virtual void dummy();    // override -> distinct vtable @0x80415280
};

AptObject::AptObject(int vftIdx, int arg)
    : AptValueWithHash(vftIdx, arg)
{
    m_state_byte = 0;
    m_state_word &= ~0x00C00000u;
}
