// 0x8027AB3C AptActionInterpreter::_FunctionAptActionStackSwap(AptActionInterpreter (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 10,0x0(3); lwz 0,0x8(3); addi 8,10,-1; rlwinm 9,10,2,0,29; rlwinm 11,8,2,0,29; add 9,9,0; add 11,11,0; lwz 7,-4(9); lwz 6,-4(11); cmpwi 10,0; ble 0f; stw 8,0x0(3); cmpwi 8,0; ble 0f; addi 0,8,-1; stw 0,0x0(3); 0:; lwz 9,0x0(3); lwz 10,0x8(3); rlwinm 11,9,2,0,29; stwx 7,11,10; addi 9,9,1; stw 9,0x0(3); rlwinm 10,9,2,0,29; lwz 11,0x8(3); addi 9,9,1; stwx 6,10,11; stw 9,0x0(3)"
extern "C" void f_8027AB3C() {}
