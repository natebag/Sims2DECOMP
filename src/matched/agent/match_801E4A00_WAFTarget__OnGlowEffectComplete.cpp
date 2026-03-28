class WAFTarget {
public:
    char pad[0x270];
    int m_glowEffect;
    void OnGlowEffectComplete(void);
};

void WAFTarget::OnGlowEffectComplete(void) {
    m_glowEffect = 0;
}
