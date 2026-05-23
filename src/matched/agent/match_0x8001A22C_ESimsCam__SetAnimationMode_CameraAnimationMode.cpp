// 0x8001A22C ESimsCam::SetAnimationMode(CameraAnimationMode, ...) (32 B)
struct ESimsCam {
    char _pad[0x478]; unsigned m_animFlag;
    char _pad2[0x554 - 0x478 - 4];
    unsigned m_animMode; unsigned m_animObj1; unsigned m_animObj2;
    void SetAnimationMode(unsigned, unsigned, unsigned, unsigned);
};
void ESimsCam::SetAnimationMode(unsigned mode, unsigned obj1, unsigned obj2, unsigned flag) {
    m_animMode = mode;
    m_animObj1 = obj1;
    m_animObj2 = obj2;
    if (!flag) return;
    m_animFlag = 1;
}
