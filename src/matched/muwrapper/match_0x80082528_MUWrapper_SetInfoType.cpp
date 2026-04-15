// FLAGS: -fno-schedule-insns
// 0x80082528 MUWrapper::SetInfoType (20B) — set 188, zero 180+184

struct MUWrapper {
    char pad[180];
    int m_displayOkType;  // +180
    int m_queryType;      // +184
    int m_infoType;       // +188
    void SetInfoType(int t);
};

void MUWrapper::SetInfoType(int t) {
    m_infoType = t;
    m_queryType = 0;
    m_displayOkType = 0;
}
