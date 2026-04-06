// 0x8005D014 SAnimator2::adjustAnimationPlayRates (56b)
// FLAGS: -fno-schedule-insns

extern void AdjustRate(void*, float);

struct SAnimator2 {
    char pad1[0x08];
    void* m_field8;     // 0x08
    char pad2[0xf4];    // 0x0c-0xff
    float m_rate1;      // 0xfc
    float m_rate2;      // 0x100
    
    void adjustAnimationPlayRates();
};

void SAnimator2::adjustAnimationPlayRates() {
    if (m_rate1 != m_rate2) {
        AdjustRate(m_field8, m_rate1);
    }
}
