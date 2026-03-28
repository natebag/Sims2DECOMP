struct EBitArray_AR;
void InsertBitsFromArray(EBitArray_AR*, EBitArray_AR*, int, int, int);

struct EBitArray_AR {
    void* m_buffer;
    int m_size;
    void Add(EBitArray_AR*);
};

void EBitArray_AR::Add(EBitArray_AR* other) {
    InsertBitsFromArray(this, other, 0, m_size, other->m_size);
}
