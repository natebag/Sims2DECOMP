// 0x802382E0 (12 bytes) - ERLevel::SetRainBlend(float)
// addis r3, r3, 3; stfs f1, -7448(r3); blr  =>  m_rainBlend = val; (offset 0x2E2E8)

struct ERLevel_SRB {
    char pad[0x2E2E8];
    float m_rainBlend;
    void SetRainBlend(float val);
};
void ERLevel_SRB::SetRainBlend(float val) {
    m_rainBlend = val;
}
