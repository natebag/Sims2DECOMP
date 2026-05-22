// 0x8027F924 AptActionInterpreter::_FunctionAptActionPushStringDictByte(AptActionInterpreter (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 10,4; lis 5,-32704; lwz 9,0x0(10); lis 4,-32704; addi 4,4,5760; addi 5,5,5812; lbz 11,0x0(9); li 6,138; addi 9,9,1; stw 9,0x0(10); rlwinm 11,11,2,0,29; lwz 10,0x38(3); lwz 9,0x0(3); lwzx 8,11,10; lwz 7,0x8(3); rlwinm 11,9,2,0,29; addi 9,9,1; stwx 8,11,7; stw 9,0x0(3); lwz 11,0x8(8); lha 3,0x8(11); lwz 0,0xc(11); add 3,8,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8027F924() {}
