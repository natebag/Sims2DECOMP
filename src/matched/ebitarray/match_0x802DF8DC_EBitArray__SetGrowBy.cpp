// 0x802DF8DC EBitArray::SetGrowBy(int) (16B)

class EBitArray {
public:
    unsigned int* m_data;  // 0x00
    int m_numBits;         // 0x04
    int m_capacity;        // 0x08
    int m_growBy;          // 0x0C
    void SetGrowBy(int growBy);
};

void EBitArray::SetGrowBy(int growBy) {
    m_growBy = (growBy + 31) & ~31;
}
