// FLAGS: -fno-elide-constructors
// EBitArray::EBitArray(int, int) - 0x802DF5F8 (100 bytes)

struct EBitArray {
    int* m_pBuffer;      // 0x00
    int m_nSize;         // 0x04  
    int m_nAllocSize;    // 0x08
    int m_field_C;       // 0x0C
    void** _vtable;      // 0x10
    
    void SetGrowBy(int);
    void SetSize(int, int);
    
    EBitArray(int size, int growBy);
};

extern void* __vt__9EBitArray[];

EBitArray::EBitArray(int size, int growBy) {
    _vtable = __vt__9EBitArray;
    // Store order 4, 0, 8 means source order: 0, 8, 4
    m_pBuffer = 0;
    m_nAllocSize = 0;
    m_nSize = 0;
    SetGrowBy(growBy);
    SetSize(size, 0);
}
