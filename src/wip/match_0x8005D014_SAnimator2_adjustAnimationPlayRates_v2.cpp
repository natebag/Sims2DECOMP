// 0x8005D014 SAnimator2::adjustAnimationPlayRates (56b)
// FLAGS: -fno-elide-constructors
// TEST: Variable declaration order to control register allocation

class SAnimator2 {
public:
    char pad[0x8];
    void* field_8;
    char pad2[0xF0];
    float field_FC;
    float field_100;
};

extern void sub_8035FEAC(void* obj);

// Declare locals in order to force r31, r30 assignment
void SAnimator2_adjustAnimationPlayRates(SAnimator2* this_) {
    register void* p1 asm("r31");  // First declared = r31
    register float f1 asm("r30");  // Second declared = r30
    
    p1 = this_->field_8;
    f1 = this_->field_FC;
    
    if (f1 != this_->field_100) {
        sub_8035FEAC((char*)p1 + 0x334);
    }
}
