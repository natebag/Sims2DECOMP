// 0x802E06F8 EBitArray::~EBitArray (76B)
// dtor: store vtable at +16; bl Deallocate; delete-flag check.

extern int VT_EBitArray[];

struct EBitArray {
    char pad[16];
    int* m_vtable;  // at +16 — set in dtor
    void Deallocate();
    ~EBitArray();
};

EBitArray::~EBitArray() {
    m_vtable = VT_EBitArray;
    Deallocate();
}
