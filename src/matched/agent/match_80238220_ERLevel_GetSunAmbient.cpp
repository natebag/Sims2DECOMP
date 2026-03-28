// 0x80238220 (12 bytes) - ERLevel::GetSunAmbient(void)
// addis r3, r3, 3; addi r3, r3, -7256; blr  =>  return &m_sunAmbient; (offset 0x2E3A8)

struct ERLevel_GSA {
    char pad[0x2E3A8];
    char m_sunAmbient;
    void* GetSunAmbient();
};
void* ERLevel_GSA::GetSunAmbient() {
    return &m_sunAmbient;
}
