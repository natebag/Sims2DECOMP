// 0x8027F2DC AptActionInterpreter::_FunctionAptActionPushNULL(AptActionInterpreter (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(3); lis 4,-32704; lwz 10,-22936(13); lis 5,-32704; lwz 8,0x8(3); rlwinm 11,9,2,0,29; addi 9,9,1; addi 4,4,5760; stwx 10,11,8; addi 5,5,5812; stw 9,0x0(3); li 6,138; lwz 9,0x8(10); lha 3,0x8(9); lwz 0,0xc(9); add 3,10,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8027F2DC() {}
