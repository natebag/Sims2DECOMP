// 0x800608DC SAnimator2::GetTurnRate(void) (76B)
// Pattern: 2 early-exits returning a hoisted const1, then field2C switch returning const2 or
// fallback m_field_98. Two non-SDA float constants in same constant pool but emitted at separate
// lis sites (cross-branch register liveness not preserved).

extern const float gTurnRate_const1[3];   // non-SDA float const at 0x803D4784
extern const float gTurnRate_const2[3];   // non-SDA float const at 0x803D4788

class SAnimator2 {
public:
    char pad_0[24];
    int m_state;             // 24 (0x18)
    char pad_28[16];
    int m_field_2C;          // 44 (0x2C)
    char pad_48[104];
    float m_field_98;        // 152 (0x98)
    char pad_156[1372];
    char m_byte_5F8;         // 1528 (0x5F8)

    float GetTurnRate();
};

float SAnimator2::GetTurnRate() {
    float r = gTurnRate_const1[0];
    int state = m_state;
    if (state == 3) return r;
    char b = m_byte_5F8;
    if (b == 2) return r;
    int f2c = m_field_2C;
    if (f2c != 12) goto check_range;
load_const2:
    return gTurnRate_const2[0];
check_range:
    if ((unsigned)(f2c - 13) <= 1) goto load_const2;
    return m_field_98;
}
