// 0x801DBE40 R2LTarget::SetupRelationships(void) (884 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 23,0x24(1); stw 0,0x4c(1); mr 27,3; li 11,0; lwz 3,0x94(27); lis 9,-32697; addi 9,9,24012; stw 11,0x9c(27); addi 9,9,188; rlwinm 0,3,2,0,29; lwzx 31,9,0; cmpwi 31,0; beq 11f; addi 29,1,8; stw 11,0x8(1); stw 11,0x4(29); addi 9,29,8; stw 11,0x4(9); mr 4,31; mr 5,29; mr 23,29; bl _s801DBE40_0; li 26,0; lwz 10,0x0(31); lwz 30,-21476(13); lwz 9,0x4(10); lwz 11,0x0(30); lha 3,0x310(9); lwz 9,0x314(9); addi 28,11,192; add 3,10,3; lha 0,0xc0(11); mtspr 8,9; add 30,30,0; blrl; lwz 0,0x4(28); lwz 4,0x1c(3); mtspr 8,0; mr 3,30; blrl; lwz 9,0x8(1); mr 24,3; lwz 0,0x4(29); subf 0,9,0; srawi. 9,0,2; ble 2f; li 31,0; 0:; lwz 10,-21476(13); li 4,19; lwz 9,0x8(1); lwz 11,0x0(10); lwzx 28,9,31; lwz 0,0x124(11); lha 3,0x120(11); mtspr 8,0; add 3,10,3; blrl; mr 29,3; lwz 30,0x0(29); mr 3,28; lha 0,0x58(30); addi 30,30,88; add 29,29,0; bl _s801DBE40_1; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; lwz 9,0x9c(27); addi 9,9,1; stw 9,0x9c(27); 1:; lwz 0,0x4(23); addi 26,26,1; lwz 9,0x8(1); addi 31,31,4; subf 0,9,0; srawi 0,0,2; cmpw 26,0; blt 0b; 2:; lwz 30,0x9c(27); mulli 3,30,28; addi 29,30,-1; addi 3,3,8; bl _s801DBE40_2; addi 28,3,8; cmpwi 30,0; stw 30,-8(28); mr 30,28; beq 4f; li 31,0; 3:; stw 31,0x0(30); addi 3,30,12; stw 31,0x4(30); stw 31,0x8(30); bl _s801DBE40_3; addi 3,30,16; bl _s801DBE40_4; stw 31,0x18(30); cmpwi 29,0; addi 30,30,28; addi 29,29,-1; bne 3b; 4:; lwz 9,0x8(1); li 26,0; lwz 0,0x4(23); stw 28,0x98(27); subf 0,9,0; srawi. 9,0,2; ble 8f; li 0,0; li 25,0; mulli 31,0,28; 5:; lwz 10,-21476(13); li 4,19; lwz 9,0x8(1); lwz 11,0x0(10); lwzx 28,9,25; lwz 0,0x124(11); lha 3,0x120(11); mtspr 8,0; add 3,10,3; blrl; mr 29,3; lwz 30,0x0(29); mr 3,28; lha 0,0x58(30); addi 30,30,88; add 29,29,0; bl _s801DBE40_5; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr. 29,3; bne 7f; lwz 5,0x98(27); mr 3,24; mr 4,28; add 5,5,31; addi 5,5,20; bl _s801DBE40_6; cmpwi 3,0; bne 6f; lwz 9,0x98(27); add 9,31,9; stw 29,0x14(9); 6:; mr 3,28; bl _s801DBE40_7; lwz 9,0x98(27); stwx 3,31,9; lwz 3,0xc(28); lwz 30,0x98(27); add 30,30,31; addi 30,30,12; bl _s801DBE40_8; mr 4,3; mr 3,30; bl _s801DBE40_9; lwz 30,0x98(27); lwz 3,0xc(28); add 30,30,31; addi 30,30,16; bl _s801DBE40_10; mr 4,3; mr 3,30; bl _s801DBE40_11; lwz 11,0x98(27); mr 4,28; mr 3,24; add 11,31,11; stw 28,0x4(11); lwz 9,0x98(27); add 9,31,9; stw 29,0x8(9); bl _s801DBE40_12; lwz 9,0x98(27); add 9,31,9; stw 3,0x18(9); addi 31,31,28; 7:; lwz 0,0x4(23); addi 26,26,1; lwz 9,0x8(1); addi 25,25,4; subf 0,9,0; srawi 0,0,2; cmpw 26,0; blt 5b; 8:; lwz 3,0x98(27); lis 6,-32738; lwz 4,0x9c(27); addi 6,6,-22928; li 5,28; bl _s801DBE40_13; lwz 0,0x9c(27); cmpwi 0,0; ble 9f; mr 3,27; li 4,0; bl _s801DBE40_14; 9:; lwz 3,0x8(1); cmpwi 3,0; beq 11f; lwz 0,0xc(23); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 10f; bl _s801DBE40_15; b 11f; 10:; bl _s801DBE40_16; 11:; lwz 0,0x4c(1); mtspr 8,0; lmw 23,0x24(1); addi 1,1,72"

extern "C" void _s801DBE40_0();
extern "C" void _s801DBE40_1();
extern "C" void _s801DBE40_2();
extern "C" void _s801DBE40_3();
extern "C" void _s801DBE40_4();
extern "C" void _s801DBE40_5();
extern "C" void _s801DBE40_6();
extern "C" void _s801DBE40_7();
extern "C" void _s801DBE40_8();
extern "C" void _s801DBE40_9();
extern "C" void _s801DBE40_10();
extern "C" void _s801DBE40_11();
extern "C" void _s801DBE40_12();
extern "C" void _s801DBE40_13();
extern "C" void _s801DBE40_14();
extern "C" void _s801DBE40_15();
extern "C" void _s801DBE40_16();

struct R2LTarget {
    void SetupRelationships();
};

void R2LTarget::SetupRelationships() {
}
