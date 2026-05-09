// Interaction::SetUniqueID(void) @ 0x801534EC (20B)
// FLAGS: -fno-schedule-insns
// DOL: li r0,-1; stw r11,4(r3); stw r0,88(r3); stw r0,84(r3); blr
// Compiler generates stw r0,4(r3) but DOL uses r11; replace first store.
// ASMPROC_replace_insn: match="stw 0,4(3)" replacement="stw 11,4(3)"

struct Interaction_SUI {
    char _pad0[4];
    int m_f4;    // offset 4
    char _pad8[76];
    int m_f54;   // offset 84
    int m_f58;   // offset 88
    void SetUniqueID();
};

void Interaction_SUI::SetUniqueID() {
    int x = -1;
    m_f4 = x;
    m_f58 = x;
    m_f54 = x;
}
