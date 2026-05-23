// 0x800679E8 SAnimator2::DrawPropsShadow(ERC (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 30,3; mr 26,4; lwz 3,0x8(30); bl _s800679E8_0; cmpwi 3,0; bne 3f; addi 9,30,360; lwz 11,0x168(30); lwz 0,0x4(9); mr 27,9; li 28,0; subf 0,11,0; srawi. 9,0,2; ble 3f; lis 25,-32692; li 29,0; 0:; lwz 31,0x168(30); lwzx 4,31,29; lwz 0,0x8(4); cmpwi 0,0; bne 1f; lwz 4,0x0(4); addi 3,25,-27556; bl _s800679E8_1; lwzx 9,31,29; stw 3,0x8(9); 1:; lwz 9,0x168(30); lwzx 3,9,29; lwz 0,0x4(3); cmpwi 0,0; beq 2f; lwz 3,0x8(3); cmpwi 3,0; beq 2f; mr 4,26; bl _s800679E8_2; 2:; lwz 0,0x4(27); addi 28,28,1; lwz 9,0x168(30); addi 29,29,4; subf 0,9,0; srawi 0,0,2; cmpw 28,0; blt 0b; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s800679E8_0();
extern "C" void _s800679E8_1();
extern "C" void _s800679E8_2();

struct SAnimator2 {
    void DrawPropsShadow_ERC();
};

void SAnimator2::DrawPropsShadow_ERC() {
}
