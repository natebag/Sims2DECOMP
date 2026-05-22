// 0x80059A84 PlumbBob::ShutdownAll(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); addi 29,13,-21420; li 28,0; li 31,0; li 30,2; 0:; lwzx 0,31,29; mr 3,0; cmpwi 0,0; beq 2f; bl _s80059A84_0; lwzx 0,31,29; li 4,3; mr 3,0; cmpwi 0,0; beq 1f; bl _s80059A84_1; 1:; stwx 28,31,29; 2:; addi 31,31,4; addic. 30,30,-1; bne 0b; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80059A84_0();
extern "C" void _s80059A84_1();
extern "C" void f_80059A84() {}
