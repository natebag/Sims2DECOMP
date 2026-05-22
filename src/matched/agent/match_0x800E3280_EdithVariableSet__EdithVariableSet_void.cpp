// 0x800E3280 EdithVariableSet::EdithVariableSet(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; li 4,0; li 5,12; bl _s800E3280_0; li 0,0; addi 9,30,20; stw 0,0xc(30); mr 3,30; stw 0,0x10(30); stw 0,0x4(9); sth 0,0x2c(30); sth 0,0x1e(30); sth 0,0x20(30); sth 0,0x22(30); sth 0,0x26(30); sth 0,0x28(30); sth 0,0x24(30); sth 0,0x2a(30); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800E3280_0();
extern "C" void f_800E3280() {}
