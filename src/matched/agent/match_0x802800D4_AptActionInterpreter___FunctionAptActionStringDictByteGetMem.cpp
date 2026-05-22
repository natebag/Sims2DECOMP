// 0x802800D4 AptActionInterpreter::_FunctionAptActionStringDictByteGetMember(AptActionInterpreter (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 30,3; lwz 9,0x0(29); lis 4,-32704; lis 5,-32704; addi 4,4,5760; lbz 11,0x0(9); addi 5,5,5812; addi 9,9,1; li 6,138; stw 9,0x0(29); rlwinm 11,11,2,0,29; lwz 10,0x38(30); lwz 9,0x0(30); lwzx 8,11,10; lwz 7,0x8(30); rlwinm 11,9,2,0,29; addi 9,9,1; stwx 8,11,7; stw 9,0x0(30); lwz 11,0x8(8); lha 3,0x8(11); lwz 0,0xc(11); add 3,8,3; mtspr 8,0; blrl; mr 3,30; mr 4,29; bl _s802800D4_0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802800D4_0();
extern "C" void f_802800D4() {}
