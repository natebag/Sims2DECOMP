// 0x802DFCC4 EBitArray::GetElementCount(void) const (16B)

class EBitArray {
public:
    unsigned int* m_data;  // 0x00
    int m_numBits;         // 0x04
    int m_capacity;        // 0x08
    int m_growBy;          // 0x0C
    int GetElementCount() const;
};

int EBitArray::GetElementCount() const {
    return ((unsigned)m_numBits + 31u) >> 5;
}
