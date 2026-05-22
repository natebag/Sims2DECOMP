// 0x8027AAD4 AptActionInterpreter::_FunctionAptActionPushDuplicate(AptActionInterpreter (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 10,0x0(3); lis 4,-32704; lwz 7,0x8(3); lis 5,-32704; rlwinm 8,10,2,0,29; addi 4,4,5760; add 9,8,7; addi 10,10,1; lwz 11,-4(9); addi 5,5,5812; li 6,138; stwx 11,8,7; stw 10,0x0(3); lwz 9,0x8(11); lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8027AAD4() {}
