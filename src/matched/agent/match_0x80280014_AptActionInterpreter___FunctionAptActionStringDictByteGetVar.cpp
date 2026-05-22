// 0x80280014 AptActionInterpreter::_FunctionAptActionStringDictByteGetVar(AptActionInterpreter (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,0x0(4); mr 31,3; lwz 5,0x8(4); lbz 11,0x0(9); addi 9,9,1; lwz 8,0x4(4); stw 9,0x0(4); rlwinm 11,11,2,0,29; lwz 9,0x38(31); lwzx 10,11,9; lwz 0,0x0(10); rlwinm 0,0,0,25,31; cmpwi 0,1; beq 0f; lwz 10,0x24(10); 0:; mr 4,8; addi 6,10,12; li 9,0; mr 3,31; li 7,1; li 8,1; bl _s80280014_0; lwz 9,0x0(31); lis 4,-32704; lwz 10,0x8(31); lis 5,-32704; rlwinm 11,9,2,0,29; addi 4,4,5760; stwx 3,11,10; addi 9,9,1; stw 9,0x0(31); addi 5,5,5812; li 6,138; lwz 9,0x8(3); lha 0,0x8(9); lwz 9,0xc(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80280014_0();
extern "C" void f_80280014() {}
