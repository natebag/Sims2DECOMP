class EBitArray {
public:
    int m_pBuf;
    int m_nSize;
    int GetSize() const;
};
int EBitArray::GetSize() const { return m_nSize; }
