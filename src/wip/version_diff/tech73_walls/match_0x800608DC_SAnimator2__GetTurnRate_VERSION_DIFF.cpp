// SAnimator2::GetTurnRate(void) - 0x800608DC (76 bytes)
// Multi-predicate float selector with range-check subtract-bias idiom.
// 4 conditions: state==3, byte==2, field==12, field in [13,14] all return K_ALT
// (last 2 tail-merge); else returns member m_field_98.
//
// VERSION_DIFF: basic-block layout-pass wall.
// 76B exact, instruction count matches, all 19 ops correct, all relocs correct.
// Only diff: layout of K_ALT block.
//   DOL: K_ALT placed BEFORE range check; range check uses BACK-JUMP (ble back).
//   Mine: K_ALT placed AFTER range check; range check uses forward jump (ble forward).
// 2 source variants tested (if-cascade, goto-fail). GCC's basic-block layout
// pass consistently puts K_ALT after the m_field_98 fall-through path.
// MutatorSmith candidate: BB-layout flip / hot-block hoist directive.
//
// FLAGS: -msdata=eabi -G 8

extern char g_K_DEFAULT_holder[16];
extern char g_K_ALT_holder[16];

struct SAnimator2 {
    char pad_0[24];
    int m_state;            // 0x18
    char pad_1c[44 - 28];
    int m_field_2c;         // 0x2c
    char pad_30[152 - 48];
    float m_field_98;       // 0x98
    char pad_9c[1528 - 156];
    unsigned char m_byte_5f8; // 0x5f8

    float GetTurnRate();
};

float SAnimator2::GetTurnRate() {
    float def = *(float*)g_K_DEFAULT_holder;
    if (m_state == 3) return def;
    if (m_byte_5f8 == 2) return def;
    int x = m_field_2c;
    if (x == 12) goto load_alt;
    if ((unsigned)(x - 13) <= 1) goto load_alt;
    return m_field_98;
load_alt:
    return *(float*)g_K_ALT_holder;
}
