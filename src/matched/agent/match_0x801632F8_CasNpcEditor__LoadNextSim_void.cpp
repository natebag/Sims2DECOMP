// 0x801632F8 CasNpcEditor::LoadNextSim(void) (752 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-632(1); mfspr 0,8; stmw 27,0x264(1); stw 0,0x27c(1); mr 31,3; lwz 0,0x8(31); cmpwi 0,1; bne 1f; addi 29,1,12; addi 30,1,8; mr 3,29; bl _s801632F8_0; lwz 4,0x10(31); mr 5,30; mr 3,31; bl _s801632F8_1; cmpwi 3,0; beq 5f; lis 9,-32698; lwz 28,0x0(31); addi 9,9,24616; addi 3,1,312; stw 9,0x134(1); addi 30,1,304; bl _s801632F8_2; li 0,0; mr 3,29; stw 0,0x130(1); addi 9,1,312; li 11,288; 0:; lwz 0,0x0(3); addic. 11,11,-24; stw 0,0x0(9); lwz 0,0x4(3); stw 0,0x4(9); lwz 0,0x8(3); stw 0,0x8(9); lwz 0,0xc(3); stw 0,0xc(9); lwz 0,0x10(3); stw 0,0x10(9); lwz 0,0x14(3); addi 3,3,24; stw 0,0x14(9); addi 9,9,24; bne 0b; lwz 0,0x0(3); mr 4,30; mr 3,28; stw 0,0x0(9); bl _s801632F8_3; lis 9,-32698; mr 3,30; addi 9,9,24616; li 4,2; stw 9,0x134(1); b 3f; 1:; cmpwi 0,2; bne 4f; lwz 4,0x10(31); cmplwi 4,51; bgt 8f; mr 3,31; bl _s801632F8_4; mr. 29,3; beq 5f; lis 9,-32698; addi 11,1,8; addi 9,9,24616; addi 30,11,8; stw 9,0x4(11); mr 3,30; mr 27,11; lwz 28,0x0(31); bl _s801632F8_5; li 0,0; mr 3,29; stw 0,0x8(1); li 9,288; 2:; lwz 0,0x0(3); addic. 9,9,-24; stw 0,0x0(30); lwz 0,0x4(3); stw 0,0x4(30); lwz 0,0x8(3); stw 0,0x8(30); lwz 0,0xc(3); stw 0,0xc(30); lwz 0,0x10(3); stw 0,0x10(30); lwz 0,0x14(3); addi 3,3,24; stw 0,0x14(30); addi 30,30,24; bne 2b; lwz 0,0x0(3); addi 4,1,8; mr 3,28; stw 0,0x0(30); bl _s801632F8_6; lis 9,-32698; mr 3,27; addi 9,9,24616; li 4,2; stw 9,0x4(27); 3:; bl _s801632F8_7; lwz 9,0x0(31); li 4,32; li 5,32; li 6,8; lwz 30,0x14(9); li 7,0; li 8,0; mr 3,30; bl _s801632F8_8; mr 4,3; mr 3,30; bl _s801632F8_9; b 8f; 4:; cmpwi 0,3; bne 8f; lwz 4,0x10(31); cmplwi 4,161; bgt 8f; mr 3,31; bl _s801632F8_10; mr. 29,3; bne 6f; 5:; li 3,0; b 9f; 6:; lis 9,-32698; addi 11,1,8; addi 9,9,24616; addi 30,11,8; stw 9,0x4(11); mr 3,30; mr 27,11; lwz 28,0x0(31); bl _s801632F8_11; li 0,0; mr 3,29; stw 0,0x8(1); li 9,288; 7:; lwz 0,0x0(3); addic. 9,9,-24; stw 0,0x0(30); lwz 0,0x4(3); stw 0,0x4(30); lwz 0,0x8(3); stw 0,0x8(30); lwz 0,0xc(3); stw 0,0xc(30); lwz 0,0x10(3); stw 0,0x10(30); lwz 0,0x14(3); addi 3,3,24; stw 0,0x14(30); addi 30,30,24; bne 7b; lwz 0,0x0(3); addi 4,1,8; mr 3,28; stw 0,0x0(30); bl _s801632F8_12; lis 9,-32698; mr 3,27; addi 9,9,24616; li 4,2; stw 9,0x4(27); bl _s801632F8_13; lwz 9,0x0(31); li 4,32; li 5,32; li 6,8; lwz 30,0x14(9); li 7,0; li 8,0; mr 3,30; bl _s801632F8_14; mr 4,3; mr 3,30; bl _s801632F8_15; 8:; li 3,1; 9:; lwz 0,0x27c(1); mtspr 8,0; lmw 27,0x264(1); addi 1,1,632"
extern "C" void _s801632F8_0();
extern "C" void _s801632F8_1();
extern "C" void _s801632F8_2();
extern "C" void _s801632F8_3();
extern "C" void _s801632F8_4();
extern "C" void _s801632F8_5();
extern "C" void _s801632F8_6();
extern "C" void _s801632F8_7();
extern "C" void _s801632F8_8();
extern "C" void _s801632F8_9();
extern "C" void _s801632F8_10();
extern "C" void _s801632F8_11();
extern "C" void _s801632F8_12();
extern "C" void _s801632F8_13();
extern "C" void _s801632F8_14();
extern "C" void _s801632F8_15();
extern "C" void f_801632F8() {}
