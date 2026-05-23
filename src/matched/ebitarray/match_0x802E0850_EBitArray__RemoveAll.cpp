// 0x802E0850 (40B) EBitArray::RemoveAll(void)
// Delegates to SetSize(0, 0).

struct EBitArray {
    void SetSize(int, int);
    void RemoveAll();
};

void EBitArray::RemoveAll() {
    SetSize(0, 0);
}
