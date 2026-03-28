// 0x80238238 (12 bytes) - ERLevel::SetRainInfoTable(levelraininfo *)
// addis r3, r3, 3; stw r4, -7080(r3); blr  =>  m_rainInfoTable = val; (offset 0x2E458)

struct ERLevel_SRIT {
    char pad[0x2E458];
    void* m_rainInfoTable;
    void SetRainInfoTable(void* val);
};
void ERLevel_SRIT::SetRainInfoTable(void* val) {
    m_rainInfoTable = val;
}
