// 0x80238244 (12 bytes) - ERLevel::SetSunYawOffset(float)
// addis r3, r3, 3; stfs f1, -7076(r3); blr  =>  m_sunYawOffset = val; (offset 0x2E45C)

struct ERLevel_SYO {
    char pad[0x2E45C];
    float m_sunYawOffset;
    void SetSunYawOffset(float val);
};
void ERLevel_SYO::SetSunYawOffset(float val) {
    m_sunYawOffset = val;
}
