// EBitArray::EBitArray(EBitArray&) - 0x802DF65C (96B)
// FLAGS: -fno-schedule-insns -fno-elide-constructors
// ASMPROC_swap_adj: a=stw b=li which=first
// ASMPROC_swap_adj: a=mr b=mr which=first

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;
    void** _vtable;

    void SetGrowBy(int growBy);
    EBitArray& operator=(EBitArray& other);
    EBitArray(EBitArray& src);
};

extern void* __vt__9EBitArray[];

EBitArray::EBitArray(EBitArray& src) {
    _vtable = __vt__9EBitArray;
    m_nSize = 0;
    m_pBuffer = 0;
    m_nAllocSize = 0;
    SetGrowBy(4096);
    *this = src;
}
