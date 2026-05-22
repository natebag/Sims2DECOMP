// 0x8027EC04 AptActionInterpreter::_FunctionAptActionBranchAlways(AptActionInterpreter (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(4); lwz 10,-27600(13); addi 9,9,3; rlwinm 9,9,0,0,29; addi 0,9,4; stw 0,0x0(4); lwz 11,0x0(9); add 0,0,11; stw 0,0x0(4); lwz 9,0x4(10); cmpwi 9,0; beq 0f; lwz 0,0x0(3); cmpwi 0,0; bne 0f; mr 3,10; bl _s8027EC04_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8027EC04_0();
extern "C" void f_8027EC04() {}
