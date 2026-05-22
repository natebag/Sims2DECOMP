// 0x802E2830 EApp::GetArg(char (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-560(1); mfspr 0,8; stmw 25,0x214(1); stw 0,0x234(1); mr 29,3; li 25,0; mr. 26,4; bne 1f; lwz 9,0x34c(29); lwz 25,0x0(9); b 3f; 0:; lwz 30,0x34c(29); mr 3,26; bl _s802E2830_0; lwzx 0,28,30; add 25,0,3; b 3f; 1:; lwz 0,0x348(29); li 27,0; cmpw 25,0; bge 3f; addi 31,1,8; li 28,0; 2:; lwz 9,0x34c(29); li 5,512; mr 3,31; addi 4,31,8; lwzx 30,28,9; bl _s802E2830_1; mr 4,30; mr 3,31; bl _s802E2830_2; mr 3,31; mr 4,26; bl _s802E2830_3; cmpwi 3,0; beq 0b; lwz 0,0x348(29); addi 27,27,1; addi 28,28,4; cmpw 27,0; blt 2b; 3:; mr 3,25; lwz 0,0x234(1); mtspr 8,0; lmw 25,0x214(1); addi 1,1,560"
extern "C" void _s802E2830_0();
extern "C" void _s802E2830_1();
extern "C" void _s802E2830_2();
extern "C" void _s802E2830_3();
extern "C" void f_802E2830() {}
