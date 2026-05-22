// 0x800A7E0C Swizzle4(void (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; lha 9,0x0(30); addi 3,1,8; lha 0,0x2(30); sth 9,0x8(1); sth 0,0xa(1); bl _s800A7E0C_0; addi 3,1,10; bl _s800A7E0C_1; lhz 0,0xa(1); lhz 9,0x8(1); sth 0,0x0(30); sth 9,0x2(30); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800A7E0C_0();
extern "C" void _s800A7E0C_1();
extern "C" void f_800A7E0C() {}
