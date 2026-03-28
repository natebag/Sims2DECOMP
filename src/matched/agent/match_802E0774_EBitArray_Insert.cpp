struct EBitArray_Ins;
void InsertBitsAtPos(EBitArray_Ins*, EBitArray_Ins*, int, int, int);

struct EBitArray_Ins {
    void* m_buffer;
    int m_size;
    void Insert(EBitArray_Ins*, int);
};

void EBitArray_Ins::Insert(EBitArray_Ins* other, int pos) {
    InsertBitsAtPos(this, other, 0, pos, other->m_size);
}
