// 0x802E274C EApp::SetArgs(int, (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-1080(1); mfspr 0,8; stmw 24,0x418(1); stw 0,0x43c(1); mr 25,3; mr 26,4; li 0,0; mr 29,5; stb 0,0x350(25); cmplwi 26,100; ble 0f; li 26,0; 0:; li 27,0; cmpw 27,26; bge 3f; lis 24,-32702; addi 31,1,8; li 28,0; 1:; cmpwi 27,0; addi 30,25,848; beq 2f; mr 3,30; addi 4,24,-5904; bl _s802E274C_0; 2:; lwzx 4,28,29; mr 3,30; addi 27,27,1; bl _s802E274C_1; lwzx 30,28,29; li 5,512; mr 3,31; addi 4,31,8; bl _s802E274C_2; mr 4,30; mr 3,31; bl _s802E274C_3; addi 3,1,528; addi 4,1,536; li 5,512; bl _s802E274C_4; addi 4,1,528; mr 3,31; li 5,34; bl _s802E274C_5; lwzx 3,28,29; lwz 4,0x8(1); addi 28,28,4; bl _s802E274C_6; cmpw 27,26; blt 1b; 3:; stw 29,0x34c(25); stw 26,0x348(25); lwz 0,0x43c(1); mtspr 8,0; lmw 24,0x418(1); addi 1,1,1080"
extern "C" void _s802E274C_0();
extern "C" void _s802E274C_1();
extern "C" void _s802E274C_2();
extern "C" void _s802E274C_3();
extern "C" void _s802E274C_4();
extern "C" void _s802E274C_5();
extern "C" void _s802E274C_6();
extern "C" void f_802E274C() {}
