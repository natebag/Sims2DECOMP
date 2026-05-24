// FLAGS: -fno-schedule-insns
// ASMPROC_force_reg: match="stw 0,4(3)" from_reg=0 to_reg=11
// 0x801534EC Interaction::SetUniqueID(void) (20B)

struct Interaction {
    void SetUniqueID();
};

void Interaction::SetUniqueID() {
}
