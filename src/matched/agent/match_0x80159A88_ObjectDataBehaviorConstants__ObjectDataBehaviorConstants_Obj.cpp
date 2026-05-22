// 0x80159A88 ObjectDataBehaviorConstants::ObjectDataBehaviorConstants(ObjectDataBehaviorConstants (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32698; mr 31,3; addi 9,9,22352; mr 28,4; li 0,0; stw 9,0x0(31); li 5,0; li 4,-1; sth 0,0x4(31); addi 3,31,8; bl _s80159A88_0; li 30,0; li 0,0; mr 3,28; stw 0,0x14(31); stw 0,0x10(31); bl _s80159A88_1; mr 29,3; mr 4,29; mr 3,31; bl _s80159A88_2; mr 3,28; bl _s80159A88_3; mr 4,3; mr 3,31; bl _s80159A88_4; cmpw 30,29; bge 1f; 0:; lwz 10,0x14(28); add 9,30,30; lwz 11,0x14(31); rlwinm 8,30,2,0,29; lhzx 0,9,10; sthx 0,9,11; lwz 3,0x10(31); lwz 4,0x10(28); add 3,3,8; add 4,4,8; bl _s80159A88_5; addi 0,30,1; extsh 30,0; cmpw 30,29; blt 0b; 1:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80159A88_0();
extern "C" void _s80159A88_1();
extern "C" void _s80159A88_2();
extern "C" void _s80159A88_3();
extern "C" void _s80159A88_4();
extern "C" void _s80159A88_5();
extern "C" void f_80159A88() {}
