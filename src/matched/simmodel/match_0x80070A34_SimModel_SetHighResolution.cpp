// FLAGS: -fno-schedule-insns
// 0x80070A34 SimModel::SetHighResolution(bool) (20B)

struct Child {
    char pad[12];
    int m_loRes;
};

struct SimModel {
    char pad[312];
    Child* m_child;     // +312
    char pad2[20];      // to 336
    int m_highRes;      // +336
    void SetHighResolution(bool b);
};

void SimModel::SetHighResolution(bool b) {
    Child* c = m_child;
    int inv = b ^ 1;
    m_highRes = b;
    c->m_loRes = inv;
}
