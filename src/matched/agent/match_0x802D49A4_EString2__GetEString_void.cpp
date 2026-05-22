// 0x802D49A4 EString2::GetEString(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); addi 30,1,8; mr 28,3; mr 31,4; mr 3,30; bl _s802D49A4_0; mr 27,30; mr 3,31; bl _s802D49A4_1; mr 29,3; mr 4,29; mr 3,30; bl _s802D49A4_2; addi 29,29,1; li 8,0; cmpw 8,29; bge 1f; 0:; lwz 11,0x0(31); add 9,8,8; lwz 10,0x8(1); add 9,9,11; lbz 0,0x1(9); stbx 0,10,8; addi 8,8,1; cmpw 8,29; blt 0b; 1:; mr 3,27; bl _s802D49A4_3; mr 4,3; mr 3,28; bl _s802D49A4_4; lwz 4,0x8(1); mr 3,27; bl _s802D49A4_5; mr 3,28; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s802D49A4_0();
extern "C" void _s802D49A4_1();
extern "C" void _s802D49A4_2();
extern "C" void _s802D49A4_3();
extern "C" void _s802D49A4_4();
extern "C" void _s802D49A4_5();
extern "C" void f_802D49A4() {}
