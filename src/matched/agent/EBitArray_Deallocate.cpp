// FLAGS: -fno-elide-constructors
// EBitArray::Deallocate(void) - 0x802DF72C (84 bytes)

typedef void (*FreeMemFunc)(void*, void*);

struct EBitArrayVtable {
    void* pad[6];        // 0x00-0x17
    short lha_offset;    // 0x18
    short pad2;          // 0x1A
    FreeMemFunc freeMem; // 0x1C
};

struct EBitArray {
    int* m_pBuffer;              // 0x00
    int m_nSize;                 // 0x04  
    int m_nAllocSize;            // 0x08
    int m_field_C;               // 0x0C
    EBitArrayVtable* _vtable;    // 0x10
    
    void Deallocate(void);
};

void EBitArray::Deallocate(void) {
    EBitArrayVtable* vtable = _vtable;
    FreeMemFunc freeMem = vtable->freeMem;
    short offset = vtable->lha_offset;
    freeMem((char*)this + offset, m_pBuffer);
    
    // Store order 4, 0, 8 means source order: 0, 8, 4
    m_pBuffer = 0;
    m_nAllocSize = 0;
    m_nSize = 0;
}
