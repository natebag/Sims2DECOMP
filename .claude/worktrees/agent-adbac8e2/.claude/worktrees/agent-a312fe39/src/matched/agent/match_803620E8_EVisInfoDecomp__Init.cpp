// 0x803620E8 (12 bytes)
// stw r5, 4(r3); stw r4, 0(r3); blr
class EBitArray;
class EVisInfoDecomp {
    void* m_array; // 0x00
    int m_count;   // 0x04
public:
    void Init(EBitArray* arr, int count);
};
void EVisInfoDecomp::Init(EBitArray* arr, int count) {
    m_count = count;
    m_array = arr;
}
