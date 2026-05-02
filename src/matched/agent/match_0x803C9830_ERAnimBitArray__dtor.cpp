// 0x803C9830 ERAnimBitArray::~ERAnimBitArray (96B)
// Sibling-twin to ERAnim's inline-bitArray pattern, but standalone:
// SI vtable-chained dtor, NO operator-delete override (default __builtin_delete).
//
// Inline trick inverted: ~ERAnimBitArray is OUT-OF-LINE so it emits at .text
// offset 0; ~EBitArray is INLINE so its 2-instruction body folds into the chain.

extern int VT_EBitArray[];
extern int VT_ERAnimBitArray[];

class EBitArray {
public:
    int* m_pBuffer;        // +0x00
    int m_nSize;           // +0x04
    int m_nAllocSize;      // +0x08
    int m_field_C;         // +0x0C
    int* m_vtable;         // +0x10
    void Deallocate();
    inline ~EBitArray() {
        m_vtable = VT_EBitArray;
        Deallocate();
    }
};

class ERAnimBitArray : public EBitArray {
public:
    char m_extra[56 - 20];
    ~ERAnimBitArray();
};

ERAnimBitArray::~ERAnimBitArray() {
    m_vtable = VT_ERAnimBitArray;
    Deallocate();
    // ~EBitArray() chain auto-inserted by compiler
}
