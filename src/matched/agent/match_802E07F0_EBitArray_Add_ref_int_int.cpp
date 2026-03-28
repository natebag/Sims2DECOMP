struct EBitArray_ARI;
void InsertBitsFromArray2(EBitArray_ARI*, EBitArray_ARI*, int, int, int);

struct EBitArray_ARI {
    void* m_buffer;
    int m_size;
    void Add(EBitArray_ARI*, int, int);
};

void EBitArray_ARI::Add(EBitArray_ARI* other, int start, int count) {
    InsertBitsFromArray2(this, other, start, m_size, count);
}
