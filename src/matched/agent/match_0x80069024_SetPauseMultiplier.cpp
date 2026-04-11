// 0x80069024 SAnimator2::SetPauseMultiplier (20B)
// DOL:
//   fmr f0, f1            ; copy new mult to f0
//   lfs f1, 260(r3)       ; load old field104 (return value)
//   stfs f0, 1616(r3)     ; store mult to field650
//   stfs f0, 260(r3)      ; store mult to field104
//   blr

class SAnimator2 {
public:
    char pad0[0x104];
    float field104;
    char pad1[0x650 - 0x108];
    float field650;

    float SetPauseMultiplier(float mult);
};

float SAnimator2::SetPauseMultiplier(float mult) {
    float old = field104;
    field104 = mult;
    field650 = mult;
    return old;
}
