// 0x8005D014 SAnimator2::adjustAnimationPlayRates (56b)
// FLAGS: -fno-elide-constructors
// TEST: Variable declaration order controls register allocation

struct SAnimator2 {
    char pad[0x8];
    void* field_8;
    char pad2[0xF0];
    float field_FC;
    float field_100;
};

extern void sub_8035FEAC(void* obj);

void SAnimator2_adjustAnimationPlayRates(SAnimator2* this_) {
    // Declare in order to match DOL register allocation
    // First = r31, Second = r30
    void* ptr = this_->field_8;
    float val = this_->field_FC;
    
    if (val != this_->field_100) {
        sub_8035FEAC((char*)ptr + 0x334);
    }
}
