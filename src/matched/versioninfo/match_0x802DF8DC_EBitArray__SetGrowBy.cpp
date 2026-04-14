/* EBitArray::SetGrowBy(int) at 0x802DF8DC (16B) */

struct EBitArray {
    char pad[0x0C];
    int m_growBy;

    void SetGrowBy(int growBy);
};

void EBitArray::SetGrowBy(int growBy) {
    m_growBy = (growBy + 31) & ~31;
}
