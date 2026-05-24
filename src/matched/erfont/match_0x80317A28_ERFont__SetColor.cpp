// 0x80317A28 ERFont::SetColor(float) (24B)
// ASMPROC_swap_adj: a=addi b=stfs which=first
// ASMPROC_force_reg_at_pos: match="addi 9,3,88" pos=0 from_reg=9 to_reg=3
// ASMPROC_force_reg_at_pos: match="stfs 1,12(9)" pos=1 from_reg=9 to_reg=3
// ASMPROC_force_reg_at_pos: match="stfs 1,4(9)" pos=1 from_reg=9 to_reg=3
// ASMPROC_force_reg_at_pos: match="stfs 1,8(9)" pos=1 from_reg=9 to_reg=3

struct ERFont {
    void SetColor();
};

void ERFont::SetColor() {
}
