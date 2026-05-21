// 0x80317A28 ERFont::SetColor(float) (24B)
//
// Sets 4 adjacent floats (m_rgba?) at offsets 88, 88+12, 88+4, 88+8 from
// this. DOL evaluates the first stfs THEN advances r3 in-place (`addi r3,
// r3, 88`), using r3 as the base for the remaining 3 stores. GCC emits the
// addi FIRST into r9, then stfs through r9 — same semantics, pure byte
// wall.
//
// WALL CLASS: store-order + in-place pointer-advance
//   1. Store order: DOL writes offsets 88, 12, 4, 8 in source-listed order.
//      GCC reorders to 88, 8, 12, 4 by ascending offset. Fixed via
//      volatile-on-all (MainGuy's promoted technique).
//   2. Pointer-advance: DOL advances r3 in-place (addi r3, r3, 88) AFTER
//      the first stfs. GCC computes the advanced pointer into a SEPARATE
//      register (r9) BEFORE the first stfs. Fixed via swap_adj (puts stfs
//      first) + 4x force_reg_at_pos (rename r9 dest of addi and r9 base of
//      subsequent stfs back to r3).
//
// Recipe (1 swap_adj + 4 force_reg_at_pos directives + volatile-on-all):
//
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
