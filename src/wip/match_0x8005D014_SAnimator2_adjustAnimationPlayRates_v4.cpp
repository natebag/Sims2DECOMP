// 0x8005D014 SAnimator2::adjustAnimationPlayRates (56b)
// FLAGS: -fno-elide-constructors

struct SAnimator2 {
    char pad[0x8];
    void* field_8;
    char pad2[0xF0];
    float field_FC;
    float field_100;
};

extern void sub_8035FEAC(void* obj);

void SAnimator2_adjustAnimationPlayRates(SAnimator2* this_) {
    // DOL loads field_100 first, then field_FC
    // Try reversing the comparison order
    if (this_->field_100 != this_->field_FC) {
        sub_8035FEAC((char*)this_->field_8 + 0x334);
    }
}
