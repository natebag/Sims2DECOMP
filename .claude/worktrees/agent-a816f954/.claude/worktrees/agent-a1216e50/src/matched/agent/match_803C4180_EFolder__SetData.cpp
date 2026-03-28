// 0x803C4180 (12 bytes)
// stw r4, 0(r3); stw r4, 4(r3); blr
class EFolder {
    void* m_data0; // 0x00
    void* m_data4; // 0x04
public:
    void SetData(void* d);
};
void EFolder::SetData(void* d) {
    m_data0 = d;
    m_data4 = d;
}
