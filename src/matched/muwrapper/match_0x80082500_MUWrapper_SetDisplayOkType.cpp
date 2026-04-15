// FLAGS: -fno-schedule-insns
// 0x80082500 MUWrapper::SetDisplayOkType (20B) — set 180, zero 184+188

struct MUWrapper {
    char pad[180];
    int m_displayOkType;  // +180
    int m_queryType;      // +184
    int m_infoType;       // +188
    void SetDisplayOkType(int t);
};

void MUWrapper::SetDisplayOkType(int t) {
    m_displayOkType = t;
    m_infoType = 0;
    m_queryType = 0;
}
