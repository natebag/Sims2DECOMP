// 0x80090A58 _Deque_base<StateMachineStatus (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 0,0x0(9); stw 11,0x18(9); mr 3,27; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 28,0x14(9); bl _s80090A58_0; li 3,28; bl _s80090A58_1; lis 11,-32698; mr 9,3; addi 11,11,-9952; li 0,3; mr 4,9; stw 0,0x0(9); stw 29,0xc(9); mr 3,27; stw 30,0x10(9); stw 28,0x14(9); stw 11,0x18(9); stw 29,0x4(9); stw 30,0x8(9); bl _s80090A58_2; lis 9,-32706; mr 3,27; lfs f1,-32600(9); li 4,0; bl _s80090A58_3; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s80090A58_4; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x98(31); cmpwi 0,0; bne 0f; bl _s80090A58_5; li 5,16; li 6,0; li 7,0; li 4,920; bl _s80090A58_6; lwz 4,0x9c(31); bl _s80090A58_7; stw 3,0x98(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80090A58_0();
extern "C" void _s80090A58_1();
extern "C" void _s80090A58_2();
extern "C" void _s80090A58_3();
extern "C" void _s80090A58_4();
extern "C" void _s80090A58_5();
extern "C" void _s80090A58_6();
extern "C" void _s80090A58_7();
extern "C" void f_80090A58() {}
