// FLAGS: -fno-elide-constructors
// EBitArray::EBitArray(int) - 0x802DF594 (100 bytes)

struct EBitArray {
    int* m_pBuffer;      // 0x00
    int m_nSize;         // 0x04  
    int m_nAllocSize;    // 0x08
    int m_field_C;       // 0x0C
    void** _vtable;      // 0x10
    
    void SetGrowBy(int);
    void SetSize(int, int);
    
    EBitArray(int size);
};

extern void* __vt__9EBitArray[];

EBitArray::EBitArray(int size) {
    _vtable = __vt__9EBitArray;
    // Store order for LIFO: write 0, 8, 4 to get output 4, 0, 8
    m_pBuffer = 0;
    m_nAllocSize = 0;
    m_nSize = 0;
    SetGrowBy(4096);
    SetSize(size, 0);
}
