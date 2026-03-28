void EBitArraySetBit(void* arr, int idx, int val);
struct EBA_C {
    void Clear(int idx);
};
void EBA_C::Clear(int idx) {
    EBitArraySetBit(this, idx, 0);
}
