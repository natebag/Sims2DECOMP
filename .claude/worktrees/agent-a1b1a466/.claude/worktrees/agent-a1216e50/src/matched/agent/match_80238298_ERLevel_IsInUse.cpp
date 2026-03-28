// 0x80238298 (12 bytes) - ERLevel::IsInUse(void)
// addis r3, r3, 3; lwz r3, -23888(r3); blr  =>  return m_inUse; (offset 0x2A2B0)

class ERLevel;

struct ERLevel_IIU {
    char pad[0x2A2B0];
    int m_inUse;
    int IsInUse();
};
int ERLevel_IIU::IsInUse() {
    return m_inUse;
}
