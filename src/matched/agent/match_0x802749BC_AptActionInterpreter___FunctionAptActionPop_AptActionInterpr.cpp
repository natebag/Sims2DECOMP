// 0x802749BC AptActionInterpreter::_FunctionAptActionPop(AptActionInterpreter (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 30,0x0(31); lwz 0,0x58(31); cmpw 30,0; ble 0f; cmpwi 30,0; ble 0f; lwz 0,0x8(31); rlwinm 9,30,2,0,29; lis 4,-32704; lis 5,-32704; add 9,9,0; addi 4,4,5964; lwz 11,-4(9); addi 5,5,5812; li 6,160; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x0(31); addi 9,9,-1; stw 9,0x0(31); 0:; cmpwi 30,1; bne 1f; lwz 3,-27600(13); lwz 0,0x4(3); cmpwi 0,0; beq 1f; bl _s802749BC_0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802749BC_0();
extern "C" void f_802749BC() {}
