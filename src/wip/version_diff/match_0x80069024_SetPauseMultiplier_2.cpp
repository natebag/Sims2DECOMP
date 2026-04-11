// FLAGS: -fno-schedule-insns
// 0x80069024 SAnimator2::SetPauseMultiplier (20b)

class SAnimator2 {
public:
    float field104;   // offset 0x104 = 260
    char pad[0x54C];  // padding to offset 0x650 = 1616
    float field650;   // offset 0x650 = 1616
};

void SAnimator2_SetPauseMultiplier(SAnimator2* this_, float mult) {
    float temp = this_->field104;
    this_->field650 = mult;
    this_->field104 = mult;
}

extern "C" void _ZN10SAnimator218SetPauseMultiplierEf(SAnimator2* this_, float mult) {
    SAnimator2_SetPauseMultiplier(this_, mult);
}
