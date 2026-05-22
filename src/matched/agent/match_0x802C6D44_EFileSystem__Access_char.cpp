// 0x802C6D44 EFileSystem::Access(char (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-864(1); mfspr 0,8; stmw 25,0x344(1); stw 0,0x364(1); mr 31,3; mr 25,4; lwz 0,0x14(31); mr 26,5; mr 28,6; cmpwi 0,0; bne 0f; lwz 9,0x0(31); lis 4,-32768; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; 0:; mr 3,31; mr 4,26; addi 5,1,824; li 27,0; bl _s802C6D44_0; cmpwi 3,0; beq 3f; lis 0,-32768; stw 27,0x33c(1); cmpw 28,0; bne 1f; lwz 28,0x10(31); 1:; lwz 0,0x338(1); addi 30,1,8; li 5,260; mr 3,30; rlwinm 0,0,0,30,28; addi 4,30,8; stw 0,0x338(1); bl _s802C6D44_1; mr 4,25; mr 3,30; bl _s802C6D44_2; lwz 29,0x338(1); addi 3,1,552; addi 4,1,560; li 5,260; bl _s802C6D44_3; addi 4,1,552; mr 3,30; bl _s802C6D44_4; lwz 30,0x228(1); addi 3,1,280; addi 4,1,288; li 5,260; bl _s802C6D44_5; mr 4,30; addi 3,1,280; bl _s802C6D44_6; lwz 7,0x118(1); mr 5,29; mr 3,31; mr 4,28; li 6,2; bl _s802C6D44_7; mr. 9,3; stw 27,0x33c(1); beq 3f; mr 4,25; mr 5,26; mr 6,28; li 3,0; li 7,2; li 8,0; mtspr 8,9; li 27,1; blrl; cmpwi 3,0; stw 3,0x33c(1); bne 2f; li 27,0; b 3f; 2:; mr 3,31; addi 4,1,828; bl _s802C6D44_8; 3:; mr 3,27; lwz 0,0x364(1); mtspr 8,0; lmw 25,0x344(1); addi 1,1,864"
extern "C" void _s802C6D44_0();
extern "C" void _s802C6D44_1();
extern "C" void _s802C6D44_2();
extern "C" void _s802C6D44_3();
extern "C" void _s802C6D44_4();
extern "C" void _s802C6D44_5();
extern "C" void _s802C6D44_6();
extern "C" void _s802C6D44_7();
extern "C" void _s802C6D44_8();
extern "C" void f_802C6D44() {}
