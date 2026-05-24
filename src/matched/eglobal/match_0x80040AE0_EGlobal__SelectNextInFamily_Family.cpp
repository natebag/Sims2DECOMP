// 0x80040AE0 EGlobal::SelectNextInFamily(Family (488 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 26,4; mr 27,3; lwz 9,0x0(26); addi 31,5,1; mr 28,6; lwz 25,-21484(13); lha 3,0x30(9); lwz 0,0x34(9); add 3,26,3; mtspr 8,0; blrl; mr 24,3; cmpw 31,24; bge 2f; 0:; lwz 9,0x0(26); mr 4,31; lwz 11,0x0(25); lwz 0,0x3c(9); lha 3,0x38(9); addi 29,11,232; mtspr 8,0; lha 30,0xe8(11); add 3,26,3; add 30,25,30; blrl; lwz 0,0x4(29); lwz 4,0x0(3); mr 3,30; mtspr 8,0; blrl; mr. 29,3; beq 1f; lwz 11,0x0(29); lwz 9,0x4(11); lwz 0,0x524(9); lha 3,0x520(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x0(29); mr 30,3; lwz 9,0x4(11); lwz 0,0x524(9); lha 3,0x520(9); mtspr 8,0; add 3,11,3; blrl; addi 3,3,40; li 4,11; bl _s80040AE0_0; lha 9,0x64(30); lha 0,0x0(3); cmpw 9,0; bne 1f; mr 3,27; mr 4,28; bl _s80040AE0_1; cmpw 29,3; beq 1f; lwz 3,0x0(29); li 4,64; lwz 9,0x4(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 1f; lwz 3,0x0(29); lwz 9,0x4(3); lha 0,0x1a8(9); lwz 9,0x1ac(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 1f; lwz 3,0x0(29); li 4,34; lwz 9,0x4(3); lha 0,0x260(9); lwz 9,0x264(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 1f; mr 3,27; mr 4,28; mr 5,29; bl _s80040AE0_2; cmpwi 3,0; bne 1f; lwz 9,0x4(29); mr 4,28; lha 3,0x120(9); lwz 0,0x124(9); add 3,29,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; mr 3,27; mr 4,28; mr 5,29; bl _s80040AE0_3; li 3,1; b 3f; 1:; addi 31,31,1; cmpw 31,24; blt 0b; 2:; li 3,0; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"

extern "C" void _s80040AE0_0();
extern "C" void _s80040AE0_1();
extern "C" void _s80040AE0_2();
extern "C" void _s80040AE0_3();

struct EGlobal {
    void SelectNextInFamily_Family();
};

void EGlobal::SelectNextInFamily_Family() {
}
