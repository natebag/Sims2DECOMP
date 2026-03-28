struct EBitArray_E {
    void Resize(int, int);
    void Empty();
};

void EBitArray_E::Empty() {
    Resize(0, 0);
}
