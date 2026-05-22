// 0x8013DE7C SeqResFile::Create(StringBuffer (396 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-424(1); mfspr 0,8; stmw 20,0x178(1); stw 0,0x1ac(1); addi 30,1,8; mr 27,3; mr 23,30; mr 22,4; li 24,-250; li 31,7; 0:; mr 3,30; addi 4,30,8; li 5,32; addi 30,30,40; bl _s8013DE7C_0; cmpwi 31,0; addi 31,31,-1; bne 0b; addi 9,27,208; li 31,0; lwzx 11,9,31; li 0,0; mr 26,9; stw 0,0x170(1); cmpwi 11,0; beq 9f; lis 9,-32698; lis 11,-32698; addi 20,9,-2920; addi 21,11,-2896; addi 25,1,328; 1:; li 29,0; li 30,0; addi 28,31,1; b 3f; 2:; addi 30,30,1; 3:; lwz 0,0x170(1); cmpw 30,0; bge 4f; addi 4,1,336; li 5,32; addi 3,1,328; bl _s8013DE7C_1; mulli 4,31,20; mr 3,25; add 4,4,27; addi 4,4,212; bl _s8013DE7C_2; mulli 3,30,40; mr 4,25; add 3,23,3; bl _s8013DE7C_3; cmpwi 3,0; bne 2b; li 29,1; 4:; cmpwi 29,0; bne 8f; mulli 0,31,20; li 3,0; lwzx 0,26,0; cmpwi 0,2; beq 5f; cmpwi 0,3; beq 6f; b 7f; 5:; li 3,336; bl _s8013DE7C_4; bl _s8013DE7C_5; b 7f; 6:; li 3,336; bl _s8013DE7C_6; mr 30,3; bl _s8013DE7C_7; stw 20,0x134(30); mr 3,30; stw 21,0xc(30); 7:; mr 4,3; mr 6,31; mr 3,27; mr 5,22; addi 7,1,368; addi 8,1,8; bl _s8013DE7C_8; mr 24,3; 8:; mr 31,28; mulli 0,31,20; lwzx 9,26,0; cmpwi 9,0; bne 1b; 9:; lwz 0,0x170(1); li 3,0; cmpwi 0,0; bne 10f; mr 3,24; 10:; lwz 0,0x1ac(1); mtspr 8,0; lmw 20,0x178(1); addi 1,1,424"
extern "C" void _s8013DE7C_0();
extern "C" void _s8013DE7C_1();
extern "C" void _s8013DE7C_2();
extern "C" void _s8013DE7C_3();
extern "C" void _s8013DE7C_4();
extern "C" void _s8013DE7C_5();
extern "C" void _s8013DE7C_6();
extern "C" void _s8013DE7C_7();
extern "C" void _s8013DE7C_8();
extern "C" void f_8013DE7C() {}
