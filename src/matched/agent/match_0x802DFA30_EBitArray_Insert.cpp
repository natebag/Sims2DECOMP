// EBitArray::Insert(bool, int) - 0x802DFA30 (76 bytes)

struct EBitArray {
    void Insert(bool, int);
    void InsertElements(int, int);
    void Set(int, bool);
};

void EBitArray::Insert(bool value, int index) {
    InsertElements(index, 1);
    Set(index, value);
}
