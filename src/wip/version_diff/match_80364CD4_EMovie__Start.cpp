// 0x80364CD4 (12 bytes)
// stw r5, 4(r3); stw r4, 0(r3); blr
class EMovie {
    int m_field0; // 0x00
    int m_field4; // 0x04
public:
    void Start(int a, int b);
};
void EMovie::Start(int a, int b) {
    m_field4 = b;
    m_field0 = a;
}
