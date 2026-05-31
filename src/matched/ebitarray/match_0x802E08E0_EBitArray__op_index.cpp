// FLAGS: -fno-schedule-insns2
// 0x802E08E0 EBitArray::operator[](int) (16B)
// sret: mr r9,r3; stw r4,0(r9); stw r5,4(r9); blr  -- returns BitRef(this, index)
struct EBitArray;
struct EBitArrayBitRef {
    EBitArray* m_owner;     // 0x0
    int m_index;            // 0x4
    EBitArrayBitRef(EBitArray* owner, int index) : m_owner(owner), m_index(index) {}
};

struct EBitArray {
    EBitArrayBitRef operator[](int index);
};

EBitArrayBitRef EBitArray::operator[](int index) {
    return EBitArrayBitRef(this, index);
}
