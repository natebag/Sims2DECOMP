// 0x800A7474 StringBuffer2::assignDebug(char (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; mr 3,30; bl _s800A7474_0; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s800A7474_1; mr 31,3; mr 4,30; bl _s800A7474_2; mr 3,29; mr 4,31; bl _s800A7474_3; cmpwi 31,0; beq 0f; mr 3,31; bl _s800A7474_4; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800A7474_0();
extern "C" void _s800A7474_1();
extern "C" void _s800A7474_2();
extern "C" void _s800A7474_3();
extern "C" void _s800A7474_4();
extern "C" void f_800A7474() {}
