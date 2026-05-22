// 0x80272984 AptActionInterpreter::doFSCommand(char (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 3,-27568(13); mr 30,4; mr 29,5; bl _s80272984_0; lis 9,-32694; add 3,30,3; lwz 0,-16240(9); mr 4,29; mtspr 8,0; blrl; li 3,1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80272984_0();
extern "C" void f_80272984() {}
