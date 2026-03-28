// 0x80238368 (12 bytes) - ERLevel::GetNumVisibleInstances(void)
// addis r3, r3, 3; lwz r3, -7476(r3); blr  =>  return m_numVisibleInstances; (offset 0x2E2CC)

struct ERLevel_GNVI {
    char pad[0x2E2CC];
    int m_numVisibleInstances;
    int GetNumVisibleInstances();
};
int ERLevel_GNVI::GetNumVisibleInstances() {
    return m_numVisibleInstances;
}
