// 0x801B0950 FAMTarget::UpdateLotSelectShaders(void) (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 24,0x10(1); stw 0,0x34(1); mr 31,3; li 27,0; lwz 4,0x14c(31); bl _s801B0950_0; lwz 11,-21476(13); mr 4,3; lwz 9,0x0(11); lha 3,0x128(9); lwz 0,0x12c(9); add 3,11,3; mtspr 8,0; blrl; lis 9,-32700; mr 28,3; addi 9,9,-28156; mr 29,9; mr 24,29; mr 25,29; mr 26,29; 0:; li 30,0; cmpwi 28,0; beq 6f; lwz 9,0x0(28); mr 4,27; lha 3,0x38(9); lwz 0,0x3c(9); add 3,28,3; mtspr 8,0; blrl; mr. 4,3; beq 1f; lwz 3,-21476(13); lwz 4,0x0(4); lwz 9,0x0(3); lha 0,0xc0(9); lwz 9,0xc4(9); add 3,3,0; mtspr 8,9; blrl; mr 30,3; 1:; cmpwi 30,0; bne 2f; lwz 0,0x0(31); cmpwi 0,0; beq 7f; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lis 5,-24685; lwz 6,0x7c(31); mr 4,26; b 5f; 2:; lwz 3,0xc(30); li 0,0; stw 0,0x8(1); addi 4,1,8; bl _s801B0950_1; lwz 5,0x8(1); cmpwi 5,0; beq 4f; lwz 0,0x0(31); cmpwi 0,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lwz 6,0x7c(31); mr 4,25; li 7,0; bl _s801B0950_2; 3:; lwz 3,0x8(1); bl _s801B0950_3; b 7f; 4:; lwz 0,0x0(31); cmpwi 0,0; beq 7f; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lis 5,-24685; lwz 6,0x7c(31); mr 4,24; 5:; ori 5,5,65396; li 7,0; bl _s801B0950_4; b 7f; 6:; lwz 0,0x0(31); cmpwi 0,0; beq 7f; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lis 5,-24685; lwz 6,0x7c(31); mr 4,29; ori 5,5,65396; li 7,0; bl _s801B0950_5; 7:; addi 27,27,1; addi 29,29,255; addi 24,24,255; addi 25,25,255; addi 26,26,255; cmpwi 27,3; ble 0b; lwz 0,0x34(1); mtspr 8,0; lmw 24,0x10(1); addi 1,1,48"
extern "C" void _s801B0950_0();
extern "C" void _s801B0950_1();
extern "C" void _s801B0950_2();
extern "C" void _s801B0950_3();
extern "C" void _s801B0950_4();
extern "C" void _s801B0950_5();
extern "C" void f_801B0950() {}
