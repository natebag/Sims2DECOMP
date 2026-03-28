class EBitArray {
public:
    int m_pBuf;
    int m_nSize;
    int IsEmpty() const;
};
int EBitArray::IsEmpty() const { return m_nSize == 0; }
