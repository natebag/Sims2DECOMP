// 0x802B4358 (76B) AptValueWithHash::AptValueWithHash(AptVirtualFunctionTable_Indices, int)
//
// Derived ctor: runs the AptValue base ctor (vft index), installs the
// AptValueWithHash vtable @0x08, and constructs the embedded AptNativeHash
// member @0x0C from the int arg. Clean init-list ctor (the compiler emits the
// base-ctor / vptr-set / member-ctor sequence natively) -- no ASMPROC surgery.

struct AptValue {
    unsigned int m_flags;    // 0x00
    unsigned int m_field04;  // 0x04
    virtual void dummy();    // vptr @ 0x08 (SN: after the 2 head data words)
    AptValue(int vftIdx);
};

struct AptNativeHash {
    AptNativeHash(int n);
};

struct AptValueWithHash : public AptValue {
    AptNativeHash m_hash;    // 0x0C
    AptValueWithHash(int vftIdx, int arg);
};

AptValueWithHash::AptValueWithHash(int vftIdx, int arg)
    : AptValue(vftIdx), m_hash(arg)
{
}
