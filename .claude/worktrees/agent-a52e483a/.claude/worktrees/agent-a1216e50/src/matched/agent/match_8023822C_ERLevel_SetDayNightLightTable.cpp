// 0x8023822C (12 bytes) - ERLevel::SetDayNightLightTable(LevelLighting *)
// addis r3, r3, 3; stw r4, -7084(r3); blr  =>  m_dayNightLightTable = val; (offset 0x2E454)

class ERLevel;

struct ERLevel_SDNLT {
    char pad[0x2E454];
    void* m_dayNightLightTable;
    void SetDayNightLightTable(void* val);
};
void ERLevel_SDNLT::SetDayNightLightTable(void* val) {
    m_dayNightLightTable = val;
}
