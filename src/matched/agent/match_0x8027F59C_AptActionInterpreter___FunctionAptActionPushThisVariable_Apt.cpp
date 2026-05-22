// 0x8027F59C AptActionInterpreter::_FunctionAptActionPushThisVariable(AptActionInterpreter (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 5,0x8(4); lis 6,-32694; mr 30,3; lwz 4,0x4(4); addi 6,6,-11332; li 9,0; addi 6,6,656; li 7,1; li 8,1; bl _s8027F59C_0; lwz 9,0x0(30); lis 4,-32704; lwz 10,0x8(30); lis 5,-32704; rlwinm 11,9,2,0,29; addi 4,4,5760; stwx 3,11,10; addi 9,9,1; stw 9,0x0(30); addi 5,5,5812; li 6,138; lwz 9,0x8(3); lha 0,0x8(9); lwz 9,0xc(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8027F59C_0();
extern "C" void f_8027F59C() {}
