// FLAGS: -fno-schedule-insns
// 0x80082514 MUWrapper::SetQueryType (20B) — set 184, zero 180+188

struct MUWrapper {
    char pad[180];
    int m_displayOkType;  // +180
    int m_queryType;      // +184
    int m_infoType;       // +188
    void SetQueryType(int t);
};

void MUWrapper::SetQueryType(int t) {
    m_queryType = t;
    m_infoType = 0;
    m_displayOkType = 0;
}
