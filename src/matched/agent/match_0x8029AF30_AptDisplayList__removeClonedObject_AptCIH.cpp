// 0x8029AF30 AptDisplayList::removeClonedObject(AptCIH (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lwz 4,0x58(4); mr 30,3; lwz 3,0x0(30); li 0,0; srawi 4,4,15; stw 0,0xc(1); stw 0,0x8(1); li 5,0; addi 6,1,8; addi 7,1,12; bl _s8029AF30_0; lwz 4,0xc(1); mr 3,30; bl _s8029AF30_1; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8029AF30_0();
extern "C" void _s8029AF30_1();
extern "C" void f_8029AF30() {}
