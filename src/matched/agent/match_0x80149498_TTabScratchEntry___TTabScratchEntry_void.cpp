// 0x80149498 TTabScratchEntry::~TTabScratchEntry(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32698; mr 30,3; addi 9,9,20728; addic. 0,30,8; mr 28,4; stw 9,0x0(30); beq 1f; addi 31,30,264; cmpw 0,31; beq 1f; mr 29,0; 0:; lwzu 9,-16(31); li 4,0; lha 3,0x68(9); lwz 0,0x6c(9); add 3,31,3; mtspr 8,0; blrl; cmpw 29,31; bne 0b; 1:; andi. 0,28,1; beq 2f; mr 3,30; bl _s80149498_0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80149498_0();
extern "C" void f_80149498() {}
