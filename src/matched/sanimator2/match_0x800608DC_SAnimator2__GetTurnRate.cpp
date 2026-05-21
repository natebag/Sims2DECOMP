// 0x800608DC (76B) SAnimator2::GetTurnRate(void)
// goto shared-label: Variant A const-value share (feedback_goto_shared_label)

extern const float lbl_803D4784[3];
extern const float lbl_803D4788[3];

struct SAnimator2 {
    char pad_0[24];
    int m_state;     // 0x18 = 24
    char pad_28[16];
    int m_field_2C;  // 0x2C = 44
    char pad_48[104];
    float m_rate;    // 0x98 = 152
    char pad_156[1372];
    char m_byte_5F8; // 0x5F8 = 1528

    float GetTurnRate();
};

float SAnimator2::GetTurnRate() {
    float r = lbl_803D4784[0];
    if (m_state == 3) return r;
    char b = m_byte_5F8;
    if (b == 2) return r;
    int f2c = m_field_2C;
    if (f2c != 12) goto check_range;
load_const2:
    return lbl_803D4788[0];
check_range:
    if ((unsigned)(f2c - 13) <= 1) goto load_const2;
    return m_rate;
}
