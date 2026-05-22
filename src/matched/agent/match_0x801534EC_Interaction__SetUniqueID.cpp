// FLAGS: -fno-schedule-insns
// ASMPROC_force_reg: match="stw 0,4(3)" from_reg=0 to_reg=11
// 0x801534EC Interaction::SetUniqueID(void) (20B)
// li r0,-1; stw r11,4(r3); stw r0,0x58(r3); stw r0,0x54(r3); blr
// DOL first store uses r11 (TU-level register allocation); patch via force_reg

struct Interaction {
    char _pad0[4];
    int m_4;       // at +4
    char _pad1[76];
    int m_54;      // at +84 (0x54)
    int m_58;      // at +88 (0x58)
    void SetUniqueID();
};

void Interaction::SetUniqueID() {
    m_4 = -1;
    m_58 = -1;
    m_54 = -1;
}
