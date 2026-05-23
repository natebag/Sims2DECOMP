// EBitArray::Insert(EBitArray&, int, int, int) - 0x802DFAE8 (92B)

struct EBitArray {
    void InsertElements(int pos, int count);
    void Set(EBitArray& src, int dstStart, int srcStart, int count);
    void Insert(EBitArray& src, int dstStart, int srcStart, int count);
};

void EBitArray::Insert(EBitArray& src, int dstStart, int srcStart, int count) {
    InsertElements(srcStart, count);
    Set(src, dstStart, srcStart, count);
}
