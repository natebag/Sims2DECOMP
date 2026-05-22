// 0x8039AEE0 VMBASESetPageTableEntry (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); stw 31,0x1c(1); stw 30,0x18(1); mr 30,4; stw 29,0x14(1); mr 29,5; stw 28,0x10(1); mr 28,3; bl _s8039AEE0_0; mr 31,3; bl _s8039AEE0_1; rlwinm 0,28,10,26,31; oris 4,0,32768; stw 4,0x0(31); rlwinm 0,30,0,4,19; mr 30,3; mr 3,31; stw 0,0x4(31); li 4,8; bl _s8039AEE0_2; mr 3,28; bl _s8039AEE0_3; mr 3,29; mr 4,28; bl _s8039AEE0_4; mr 3,30; bl _s8039AEE0_5; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s8039AEE0_0();
extern "C" void _s8039AEE0_1();
extern "C" void _s8039AEE0_2();
extern "C" void _s8039AEE0_3();
extern "C" void _s8039AEE0_4();
extern "C" void _s8039AEE0_5();
extern "C" void f_8039AEE0() {}
