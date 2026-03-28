class EBitArray {
public:
    unsigned int *m_pBuf;
    unsigned int *GetBuffer();
};
unsigned int *EBitArray::GetBuffer() { return m_pBuf; }
