// 0x80209500 (16 bytes) - InteractorModule::Interactor::ResetIdleTime(void)
// Pattern: m_idleTime = 0.0f  (loads zero constant from .rodata via lis+lfs)

struct Interactor_RI {
    char pad[0x58];
    float m_idleTime; // +88 = 0x58

    void ResetIdleTime();
};

void Interactor_RI::ResetIdleTime() {
    m_idleTime = 0.0f;
}
