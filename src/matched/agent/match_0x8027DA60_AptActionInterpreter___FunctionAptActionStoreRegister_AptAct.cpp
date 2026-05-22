// 0x8027DA60 AptActionInterpreter::_FunctionAptActionStoreRegister(AptActionInterpreter (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x0(4); addi 11,11,3; rlwinm 11,11,0,0,29; addi 0,11,4; stw 0,0x0(4); lwz 9,0x0(3); lwz 0,0x8(3); rlwinm 9,9,2,0,29; lwz 3,0x0(11); add 9,9,0; lwz 4,-4(9); bl _s8027DA60_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8027DA60_0();
extern "C" void f_8027DA60() {}
