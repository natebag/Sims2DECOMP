// 0x8006559C (8 bytes) — li 3, 0; blr
// SAnimator2::StartParticleEffectFromEdithPrimitive(unsigned int, unsigned int)

class SAnimator2 {
public:
    void StartParticleEffectFromEdithPrimitive(unsigned int, unsigned int);
};

__attribute__((naked))
void SAnimator2::StartParticleEffectFromEdithPrimitive(unsigned int, unsigned int) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
