// 0x80364CD4 EMovie::Start (12b)
// FLAGS: -fno-schedule-insns

class EMovie {
    int m_field0;
    int m_field4;
public:
    void Start(int a, int b);
};

void EMovie::Start(int a, int b) {
    m_field4 = b;
    m_field0 = a;
}
