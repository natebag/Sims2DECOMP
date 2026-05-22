// 0x802BDDE0 EAStringC::UTF8_Mid(int, (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 28,3; mr 27,4; mr 29,6; mr. 30,5; bge 0f; subf 29,30,29; li 30,0; 0:; cmpwi 29,0; bgt 2f; b 6f; 1:; li 30,0; b 5f; 2:; lwz 9,0x0(27); li 31,0; cmpw 31,30; addi 26,9,8; mr 3,26; bge 4f; 3:; addi 4,1,8; bl _s802BDDE0_0; lwz 0,0x8(1); cmpwi 0,0; beq 1b; addi 31,31,1; cmpw 31,30; blt 3b; 4:; mr 30,3; 5:; cmpwi 30,0; bne 8f; 6:; lis 11,-32700; addi 0,11,-6476; stw 0,0x0(28); lhz 9,-6476(11); addi 9,9,1; sth 9,-6476(11); b 12f; 7:; li 3,0; b 10f; 8:; li 31,0; subf 26,26,30; mr 3,30; cmpw 31,29; bge 10f; 9:; addi 4,1,12; bl _s802BDDE0_1; lwz 0,0xc(1); cmpwi 0,0; beq 7b; addi 31,31,1; cmpw 31,29; blt 9b; 10:; cmpwi 3,0; bne 11f; mr 4,27; mr 5,26; mr 3,28; bl _s802BDDE0_2; b 12f; 11:; subf 6,30,3; mr 4,27; mr 5,26; mr 3,28; bl _s802BDDE0_3; 12:; mr 3,28; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s802BDDE0_0();
extern "C" void _s802BDDE0_1();
extern "C" void _s802BDDE0_2();
extern "C" void _s802BDDE0_3();
extern "C" void f_802BDDE0() {}
