// 0x802C6EA8 EFileSystem::Create(EFile (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-872(1); mfspr 0,8; stmw 22,0x340(1); stw 0,0x36c(1); mr 31,3; mr 23,4; lwz 0,0x14(31); mr 26,5; mr 25,6; mr 28,7; mr 24,8; mr 22,9; cmpwi 0,0; bne 0f; lwz 9,0x0(31); lis 4,-32768; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; 0:; mr 3,31; mr 4,25; addi 5,1,824; li 27,0; bl _s802C6EA8_0; cmpwi 3,0; beq 2f; lis 0,-32768; cmpw 28,0; bne 1f; lwz 28,0x10(31); 1:; lwz 0,0x338(1); addi 30,1,8; li 5,260; mr 3,30; rlwinm 0,0,0,30,28; addi 4,30,8; stw 0,0x338(1); bl _s802C6EA8_1; mr 4,26; mr 3,30; bl _s802C6EA8_2; lwz 29,0x338(1); addi 3,1,552; addi 4,1,560; li 5,260; bl _s802C6EA8_3; addi 4,1,552; mr 3,30; bl _s802C6EA8_4; lwz 30,0x228(1); addi 3,1,280; addi 4,1,288; li 5,260; bl _s802C6EA8_5; addi 3,1,280; mr 4,30; bl _s802C6EA8_6; lwz 7,0x118(1); mr 5,29; mr 4,28; mr 6,24; mr 3,31; bl _s802C6EA8_7; mr 0,3; stw 27,0x0(23); mr 4,26; mr 5,25; mr 6,28; mr 7,24; mr 8,22; li 3,0; mtspr 8,0; li 27,1; blrl; stw 3,0x0(23); cmpwi 3,0; bne 2f; li 27,0; 2:; mr 3,27; lwz 0,0x36c(1); mtspr 8,0; lmw 22,0x340(1); addi 1,1,872"
extern "C" void _s802C6EA8_0();
extern "C" void _s802C6EA8_1();
extern "C" void _s802C6EA8_2();
extern "C" void _s802C6EA8_3();
extern "C" void _s802C6EA8_4();
extern "C" void _s802C6EA8_5();
extern "C" void _s802C6EA8_6();
extern "C" void _s802C6EA8_7();
extern "C" void f_802C6EA8() {}
