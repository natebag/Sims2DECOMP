// 0x80272938 AptActionInterpreter::isFSCommand(char (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 30,-27568(13); mr 29,4; mr 3,30; bl _s80272938_0; mr 5,3; mr 4,30; mr 3,29; bl _s80272938_1; subfic 0,3,0; adde 3,0,3; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80272938_0();
extern "C" void _s80272938_1();
extern "C" void f_80272938() {}
