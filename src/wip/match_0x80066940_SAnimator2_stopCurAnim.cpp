// 0x80066940 SAnimator2::stopCurAnim (60b)
// FLAGS: -fno-elide-constructors

struct SAnimator2 {
    char pad[0xC8];
    int field_C8;        // 0xC8
    float field_D0;      // 0xD0
    int field_D4;        // 0xD4
    char pad2[0x4];      // 0xD8-0xDB
    int field_DC;        // 0xDC
    int field_E0;        // 0xE0
    char pad3[0x538];    // 0xE4-0x617 (0x61C - 0xE4 = 0x538)
    int field_61C;       // 0x61C
};

extern float g_zeroFloat;  // SDA at 0x803D4AF4

void SAnimator2_stopCurAnim(SAnimator2* this_, int stop) {
    if (stop) {
        this_->field_C8 = 0;
        this_->field_D0 = g_zeroFloat;
    }
    
    int val = this_->field_61C;
    val &= ~1;  // Clear bit 31
    this_->field_D4 = 0;
    this_->field_E0 = this_->field_DC;
    this_->field_61C = val;
}
