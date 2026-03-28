// 0x80238214 (12 bytes) - ERLevel::GetSun(void)
// addis r3, r3, 3; addi r3, r3, -7440; blr  =>  return &m_sun; (offset 0x2E2F0)

class ERLevel;

struct ERLevel_GS {
    char pad[0x2E2F0];
    char m_sun;
    void* GetSun();
};
void* ERLevel_GS::GetSun() {
    return &m_sun;
}
