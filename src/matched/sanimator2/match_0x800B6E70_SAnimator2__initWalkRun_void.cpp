// 0x800B6E70 SAnimator2::initWalkRun(void) (900 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x24(1); mtspr 8,0; lmw 29,0xc(1); lfd f31,0x18(1); addi 1,1,32; blr; stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 3,0xc(3); mr 5,4; li 31,0; cmpwi 3,0; beq 1f; lwz 3,0x0(3); li 4,0; cmpwi 3,0; beq 0f; lwz 4,-4(3); 0:; rlwinm 4,4,3,0,28; add 4,3,4; bl _s800B6E70_0; cmpwi 3,0; beq 1f; li 31,1; 1:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16; blr; stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 11,-21508(13); mr 30,3; mr 29,4; mr 28,5; lwz 9,0x0(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 5,28; mr 3,30; bl _s800B6E70_1; mr. 31,3; bne 2f; addi 30,30,4; mr 4,29; mr 3,30; bl _s800B6E70_2; mr 3,30; rlwinm 4,28,0,16,31; bl _s800B6E70_3; 2:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24; blr; stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr. 4,4; beq 4f; lwz 3,0x8(4); cmpwi 3,0; beq 4f; lwz 3,0x30(3); li 4,0; cmpwi 3,0; beq 3f; lwz 4,-4(3); 3:; rlwinm 4,4,3,0,28; add 4,3,4; bl _s800B6E70_4; stw 3,0xc(31); li 3,0; b 5f; 4:; li 3,-98; 5:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16; blr; stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 28,5; 6:; subf 0,30,29; srawi. 9,0,3; ble 7f; cmpwi 9,1; bne 8f; lwz 3,0x4(30); mr 4,28; bl _s800B6E70_5; cmpwi 3,0; mr 3,30; beq 11f; 7:; li 3,0; b 11f; 8:; rlwinm 0,0,1,31,31; mr 3,28; add 0,9,0; rlwinm 0,0,2,0,28; add 31,30,0; lwz 4,0x4(31); bl _s800B6E70_6; cmpwi 3,0; bne 9f; mr 3,31; b 11f; 9:; ble 10f; addi 30,31,8; b 6b; 10:; mr 29,31; b 6b; 11:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; addi 4,4,4; bl _s800B6E70_7; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(3); lha 5,0x4(4); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; lwz 4,0x0(4); mtspr 8,9; blrl; subfic 0,3,0; adde 3,0,3; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; li 3,0; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr. 30,5; beq 13f; cmpwi 4,1; beq 12f; lis 0,11244; ori 0,0,35334; cmpw 4,0; bne 13f; 12:; lwz 9,0x0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; stw 31,0x0(30); li 3,1; b 14f; 13:; li 3,0; 14:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; li 3,1; blr; mr 9,3; lwz 3,0x10(9); addi 3,3,1; stw 3,0x10(9); blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,3; lwz 9,0x10(11); addi 3,9,-1; stw 3,0x10(11); cmpwi 3,0; bne 16f; cmpwi 11,0; beq 15f; lwz 9,0x0(11); li 4,3; lha 3,0x60(9); lwz 0,0x64(9); add 3,11,3; mtspr 8,0; blrl; 15:; li 3,0; 16:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; li 3,0"

extern "C" void _s800B6E70_0();
extern "C" void _s800B6E70_1();
extern "C" void _s800B6E70_2();
extern "C" void _s800B6E70_3();
extern "C" void _s800B6E70_4();
extern "C" void _s800B6E70_5();
extern "C" void _s800B6E70_6();
extern "C" void _s800B6E70_7();

struct SAnimator2 {
    void initWalkRun();
};

void SAnimator2::initWalkRun() {
}
