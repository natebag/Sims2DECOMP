// 0x8036678C BIG_locatesize(void (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 7,5; mr 30,3; li 31,0; stw 31,0x8(1); li 5,0; addi 6,1,8; bl _s8036678C_0; lwz 0,0x8(1); cmpwi 0,0; beq 0f; add 31,30,0; 0:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8036678C_0();
extern "C" void f_8036678C() {}
