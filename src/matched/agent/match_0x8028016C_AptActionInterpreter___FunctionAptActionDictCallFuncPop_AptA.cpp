// 0x8028016C AptActionInterpreter::_FunctionAptActionDictCallFuncPop(AptActionInterpreter (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 31,3; lwz 9,0x0(30); lis 4,-32704; lis 29,-32704; addi 4,4,5760; lbz 11,0x0(9); addi 5,29,5812; addi 9,9,1; li 6,138; stw 9,0x0(30); rlwinm 11,11,2,0,29; lwz 10,0x38(31); lwz 9,0x0(31); lwzx 8,11,10; lwz 7,0x8(31); rlwinm 11,9,2,0,29; addi 9,9,1; stwx 8,11,7; stw 9,0x0(31); lwz 11,0x8(8); lha 3,0x8(11); lwz 0,0xc(11); add 3,8,3; mtspr 8,0; blrl; mr 4,30; mr 3,31; bl _s8028016C_0; lwz 9,0x0(31); cmpwi 9,0; ble 0f; lwz 0,0x8(31); rlwinm 9,9,2,0,29; lis 4,-32704; addi 5,29,5812; add 9,9,0; addi 4,4,5964; lwz 11,-4(9); li 6,160; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x0(31); addi 9,9,-1; stw 9,0x0(31); 0:; lwz 3,-27600(13); lwz 0,0x4(3); cmpwi 0,0; beq 1f; lwz 0,0x0(31); cmpwi 0,0; bne 1f; bl _s8028016C_1; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8028016C_0();
extern "C" void _s8028016C_1();
extern "C" void f_8028016C() {}
