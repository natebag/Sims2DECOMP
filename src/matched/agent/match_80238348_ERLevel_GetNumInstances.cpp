// 0x80238348 (12 bytes) - ERLevel::GetNumInstances(void)
// addis r3, r3, 3; lwz r3, -15688(r3); blr  =>  return m_numInstances; (offset 0x2C2B8)

struct ERLevel_GNI {
    char pad[0x2C2B8];
    int m_numInstances;
    int GetNumInstances();
};
int ERLevel_GNI::GetNumInstances() {
    return m_numInstances;
}
