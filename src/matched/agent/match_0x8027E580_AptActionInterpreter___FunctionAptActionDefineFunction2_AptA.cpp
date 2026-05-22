// 0x8027E580 AptActionInterpreter::_FunctionAptActionDefineFunction2(AptActionInterpreter (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,4; mr 28,3; lwz 30,0x0(31); li 4,56; lwz 3,-23016(13); addi 30,30,3; rlwinm 30,30,0,0,29; addi 0,30,28; stw 0,0x0(31); lwz 9,0x10(30); add 0,0,9; stw 0,0x0(31); lwz 9,0x34(28); lwz 10,0x38(28); stw 9,0x14(30); stw 10,0x18(30); lwz 29,0x4(31); bl _s8027E580_0; lwz 4,0x30(28); mr 6,29; mr 5,30; bl _s8027E580_1; lwz 4,0x0(30); mr 29,3; lbz 0,0x0(4); cmpwi 0,0; bne 0f; lwz 9,0x0(28); lis 4,-32704; lwz 10,0x8(28); lis 5,-32704; rlwinm 11,9,2,0,29; addi 4,4,5760; stwx 29,11,10; addi 9,9,1; stw 9,0x0(28); addi 5,5,5812; li 6,138; lwz 9,0x8(29); lha 3,0x8(9); lwz 0,0xc(9); add 3,29,3; mtspr 8,0; blrl; b 1f; 0:; addi 30,1,8; mr 3,30; bl _s8027E580_2; lwz 4,0x4(31); li 9,1; lwz 5,0x8(31); mr 3,28; mr 6,30; mr 7,29; li 8,1; li 10,0; bl _s8027E580_3; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027E580_4; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8027E580_0();
extern "C" void _s8027E580_1();
extern "C" void _s8027E580_2();
extern "C" void _s8027E580_3();
extern "C" void _s8027E580_4();
extern "C" void f_8027E580() {}
