// 0x800941F0 _Deque_base<StateMachineStatus (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 1,1,8; blr; lwz 9,0x8(3); lwz 3,0x98(9); blr; lis 11,-32698; mr 9,3; li 10,-1; li 8,0; addi 11,11,-9592; li 0,1; stw 4,0x0(9); stw 10,0xc(9); stw 8,0x10(9); stw 0,0x14(9); stw 11,0x18(9); stw 10,0x4(9); stw 8,0x8(9); blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; andi. 0,4,1; addi 9,9,-13880; stw 9,0x18(3); beq 0f; bl _s800941F0_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lwz 9,0x8(3); lwz 3,0x98(9); blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 0,3; lis 30,-32697; lis 3,-32706; stw 0,0x5b84(30); li 4,0; addi 30,30,23428; addi 3,3,-31448; bl _s800941F0_1; li 0,0; li 9,1; stw 0,0xc(29); mr 3,30; stw 9,0x28(29); li 4,0; stw 0,0x1c(29); li 5,2; stw 0,0x20(29); stw 0,0x24(29); stw 9,0x2c(29); bl _s800941F0_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800941F0_0();
extern "C" void _s800941F0_1();
extern "C" void _s800941F0_2();
extern "C" void f_800941F0() {}
