// 0x802E0828 (40B) EBitArray::Empty(void)
// Delegates to SetSize(0, 0).

struct EBitArray {
    void SetSize(int, int);
    void Empty();
};

void EBitArray::Empty() {
    SetSize(0, 0);
}
