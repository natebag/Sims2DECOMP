// 0x80197F70 CASGeneticsTarget::CreateParentTexture(unsigned (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-576(1); mfspr 0,8; stmw 26,0x228(1); stw 0,0x244(1); mr 30,3; mr 31,4; lwz 0,0x94(30); cmpwi 0,0; beq 0f; lwz 0,0x2fc(30); cmpwi 0,0; beq 0f; cmplwi 31,1; bgt 0f; rlwinm 11,31,2,0,29; addi 9,30,788; lwzx 0,9,11; mr 27,11; mr 26,9; cmpwi 0,0; beq 0f; addi 3,1,8; bl _s80197F70_0; mulli 0,31,292; addi 9,30,304; addi 3,1,8; lwzx 4,9,0; bl _s80197F70_1; addi 3,1,8; li 5,128; li 6,8; li 4,128; bl _s80197F70_2; lwz 4,0x2fc(30); addi 3,1,8; bl _s80197F70_3; addi 3,1,8; bl _s80197F70_4; mr. 28,3; bne 1f; addi 3,1,8; li 4,2; bl _s80197F70_5; 0:; li 3,0; b 5f; 1:; addi 9,13,-21168; lis 29,-32692; lwzx 3,27,9; bl _s80197F70_6; mr 30,3; addi 3,29,-7364; mr 4,30; bl _s80197F70_7; cmpwi 3,0; beq 2f; addi 3,29,-7364; mr 4,30; li 5,0; li 6,0; bl _s80197F70_8; mr 31,3; b 3f; 2:; li 4,24; li 5,8; addi 3,29,-7364; bl _s80197F70_9; bl _s80197F70_10; mr 31,3; mr 5,30; addi 3,29,-7364; mr 4,31; bl _s80197F70_11; 3:; mr 4,28; mr 3,31; bl _s80197F70_12; lwzx 3,26,27; mr 4,31; li 5,0; bl _s80197F70_13; cmpwi 31,0; beq 4f; mr 3,31; bl _s80197F70_14; 4:; addi 3,1,8; li 4,2; bl _s80197F70_15; li 3,1; 5:; lwz 0,0x244(1); mtspr 8,0; lmw 26,0x228(1); addi 1,1,576"
extern "C" void _s80197F70_0();
extern "C" void _s80197F70_1();
extern "C" void _s80197F70_2();
extern "C" void _s80197F70_3();
extern "C" void _s80197F70_4();
extern "C" void _s80197F70_5();
extern "C" void _s80197F70_6();
extern "C" void _s80197F70_7();
extern "C" void _s80197F70_8();
extern "C" void _s80197F70_9();
extern "C" void _s80197F70_10();
extern "C" void _s80197F70_11();
extern "C" void _s80197F70_12();
extern "C" void _s80197F70_13();
extern "C" void _s80197F70_14();
extern "C" void _s80197F70_15();
extern "C" void f_80197F70() {}
