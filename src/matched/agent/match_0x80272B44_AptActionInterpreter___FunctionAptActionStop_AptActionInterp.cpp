// 0x80272B44 AptActionInterpreter::_FunctionAptActionStop(AptActionInterpreter (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,0x4(4); lwz 0,0x0(31); andis. 9,0,2048; beq 1f; mr 3,31; li 30,0; bl _s80272B44_0; cmpwi 3,19; bne 0f; mr 3,31; bl _s80272B44_1; subfic 0,3,0; adde 30,0,3; 0:; cmpwi 30,0; bne 1f; lwz 3,0x4c(31); cmpwi 3,0; beq 1f; lwz 0,0x1c(3); rlwinm 0,0,0,26,24; stw 0,0x1c(3); 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80272B44_0();
extern "C" void _s80272B44_1();
extern "C" void f_80272B44() {}
