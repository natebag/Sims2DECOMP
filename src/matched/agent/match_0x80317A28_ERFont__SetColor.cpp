// 0x80317A28 ERFont::SetColor(float) (24B)
// ASMPROC_swap_adj: a=addi b=stfs which=first
// ASMPROC_force_reg_at_pos: match="addi 9,3,88" pos=0 from_reg=9 to_reg=3
// ASMPROC_force_reg_at_pos: match="stfs 1,12(9)" pos=1 from_reg=9 to_reg=3
// ASMPROC_force_reg_at_pos: match="stfs 1,4(9)" pos=1 from_reg=9 to_reg=3
// ASMPROC_force_reg_at_pos: match="stfs 1,8(9)" pos=1 from_reg=9 to_reg=3

class ERFont {
public:
    void SetColor(float c);
};

void ERFont::SetColor(float c) {
    *(volatile float*)((char*)this + 88) = c;
    char* p = (char*)this + 88;
    *(volatile float*)(p + 12) = c;
    *(volatile float*)(p + 4) = c;
    *(volatile float*)(p + 8) = c;
}
