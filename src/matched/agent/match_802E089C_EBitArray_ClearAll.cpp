void EBitArrayFill(void* arr, int val);
struct EBA_CA {
    void ClearAll();
};
void EBA_CA::ClearAll() {
    EBitArrayFill(this, 0);
}
