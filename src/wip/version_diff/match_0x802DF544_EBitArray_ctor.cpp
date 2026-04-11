// EBitArray::EBitArray(void) - 0x802DF544 (80 bytes)
// DOL store order: m_nSize (4), m_pBuffer (0), m_nAllocSize (8)

struct EBitArray {
    int* m_pBuffer;      // 0x00
    int m_nSize;         // 0x04  
    int m_nAllocSize;    // 0x08
    int m_field_C;       // 0x0C
    void** _vtable;      // 0x10
    
    void SetGrowBy(int);
    
    EBitArray(void);
};

extern void* __vt__9EBitArray[];

EBitArray::EBitArray(void) {
    _vtable = __vt__9EBitArray;
    m_pBuffer = 0;
    m_nAllocSize = 0;
    m_nSize = 0;
    SetGrowBy(4096);
}
