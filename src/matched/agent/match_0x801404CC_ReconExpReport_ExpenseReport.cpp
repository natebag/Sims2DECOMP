// 0x801404CC ReconExpReport(ExpenseReport (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); li 0,1; mr 28,4; mr 29,3; stw 0,0x8(1); mr 3,28; addi 4,1,8; li 5,1; bl _s801404CC_0; lwz 0,0x8(1); li 9,8; cmpwi 0,0; bne 0f; li 9,7; 0:; cmpwi 9,0; beq 2f; mr 30,9; li 31,0; 1:; lwzx 0,31,29; mr 3,28; addi 4,1,12; li 5,1; stw 0,0xc(1); bl _s801404CC_1; lwz 0,0xc(1); addic. 30,30,-1; stwx 0,31,29; addi 31,31,4; bne 1b; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s801404CC_0();
extern "C" void _s801404CC_1();
extern "C" void f_801404CC() {}
