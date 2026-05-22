// 0x801B2CD4 FAMTarget::UpdateFamilySelectShaders(void) (492 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 22,0x10(1); stw 0,0x3c(1); lis 9,-32701; mr 31,3; addi 22,9,29220; li 30,0; 0:; mr 4,30; mr 3,31; bl _s801B2CD4_0; li 24,0; lwz 11,-21476(13); mr 4,3; addi 23,30,1; lwz 9,0x0(11); lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,11,3; blrl; rlwinm 0,30,10,0,21; rlwinm 9,30,2,0,29; subf 0,9,0; mr 25,3; add 27,0,22; mr 28,27; mr 29,28; mr 26,29; 1:; li 30,0; cmpwi 25,0; beq 7f; lwz 9,0x0(25); mr 4,24; lha 3,0x38(9); lwz 0,0x3c(9); add 3,25,3; mtspr 8,0; blrl; mr. 4,3; beq 2f; lwz 3,-21476(13); lwz 4,0x0(4); lwz 9,0x0(3); lha 0,0xc0(9); lwz 9,0xc4(9); add 3,3,0; mtspr 8,9; blrl; mr 30,3; 2:; cmpwi 30,0; bne 3f; lwz 0,0x0(31); cmpwi 0,0; beq 8f; lwz 3,0x1c(31); cmpwi 3,0; beq 8f; lis 5,-24685; lwz 6,0x7c(31); mr 4,26; b 6f; 3:; lwz 3,0xc(30); li 0,0; stw 0,0x8(1); addi 4,1,8; bl _s801B2CD4_1; lwz 5,0x8(1); cmpwi 5,0; beq 5f; lwz 0,0x0(31); cmpwi 0,0; beq 4f; lwz 3,0x1c(31); cmpwi 3,0; beq 4f; lwz 6,0x7c(31); mr 4,29; li 7,0; bl _s801B2CD4_2; 4:; lwz 3,0x8(1); bl _s801B2CD4_3; b 8f; 5:; lwz 0,0x0(31); cmpwi 0,0; beq 8f; lwz 3,0x1c(31); cmpwi 3,0; beq 8f; lis 5,-24685; lwz 6,0x7c(31); mr 4,28; 6:; ori 5,5,65396; li 7,0; bl _s801B2CD4_4; b 8f; 7:; lwz 0,0x0(31); cmpwi 0,0; beq 8f; lwz 3,0x1c(31); cmpwi 3,0; beq 8f; lis 5,-24685; lwz 6,0x7c(31); mr 4,27; ori 5,5,65396; li 7,0; bl _s801B2CD4_5; 8:; addi 24,24,1; addi 27,27,255; addi 28,28,255; addi 29,29,255; addi 26,26,255; cmpwi 24,3; ble 1b; mr 30,23; cmpwi 30,7; ble 0b; lwz 0,0x3c(1); mtspr 8,0; lmw 22,0x10(1); addi 1,1,56"
extern "C" void _s801B2CD4_0();
extern "C" void _s801B2CD4_1();
extern "C" void _s801B2CD4_2();
extern "C" void _s801B2CD4_3();
extern "C" void _s801B2CD4_4();
extern "C" void _s801B2CD4_5();
extern "C" void f_801B2CD4() {}
