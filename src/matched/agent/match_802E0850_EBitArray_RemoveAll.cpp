struct EBitArray_RA {
    void Resize(int, int);
    void RemoveAll();
};

void EBitArray_RA::RemoveAll() {
    Resize(0, 0);
}
