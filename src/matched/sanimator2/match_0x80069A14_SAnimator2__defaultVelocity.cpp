// 0x80069A14 (120B) SAnimator2::defaultVelocity(int)

extern "C" int helper_0x800317ec(void* ptr);  // ESim::IsAdult(void)

extern float SAnimator2_defaultVelocity_consts[3];

class SAnimator2 {
public:
    float defaultVelocity(int kind);
};

float SAnimator2::defaultVelocity(int kind) {
    void* sim = *(void**)((char*)this + 8);
    if (helper_0x800317ec(sim)) {
        if (kind == 1) return SAnimator2_defaultVelocity_consts[0];
        if (kind == 8) return SAnimator2_defaultVelocity_consts[0];
        return SAnimator2_defaultVelocity_consts[1];
    }
    if (kind == 1) return SAnimator2_defaultVelocity_consts[0];
    if (kind != 8) return SAnimator2_defaultVelocity_consts[2];
    return SAnimator2_defaultVelocity_consts[0];
}
