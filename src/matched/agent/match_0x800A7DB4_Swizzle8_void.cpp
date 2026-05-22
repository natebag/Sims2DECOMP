// 0x800A7DB4 Swizzle8(void (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; lwz 9,0x0(30); addi 3,1,8; lwz 0,0x4(30); stw 9,0x8(1); stw 0,0xc(1); bl _s800A7DB4_0; addi 3,1,12; bl _s800A7DB4_1; lwz 0,0xc(1); lwz 9,0x8(1); stw 0,0x0(30); stw 9,0x4(30); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800A7DB4_0();
extern "C" void _s800A7DB4_1();
extern "C" void f_800A7DB4() {}
