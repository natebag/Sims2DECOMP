// EBitArray::operator[](int) - 0x802E08E0 (16B)
// FLAGS: -fno-schedule-insns
// ASMPROC_insert_mr: before="stw 4,0(3)" src=3 dst=9 relabel=3:9 until=blr

class EBitArray;

struct EBitArrayProxy {
    EBitArray* m_arr;
    int m_index;
    EBitArrayProxy(EBitArray* a, int i) { m_arr = a; m_index = i; }
};

class EBitArray {
public:
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    EBitArrayProxy operator[](int idx);
};

EBitArrayProxy EBitArray::operator[](int idx) {
    return EBitArrayProxy(this, idx);
}
