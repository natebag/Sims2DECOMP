// 0x8029AEC4 AptDisplayList::removeObject(int) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; li 5,0; lwz 3,0x0(30); addi 6,1,8; addi 7,1,12; bl _s8029AEC4_0; lwz 4,0xc(1); mr 3,30; bl _s8029AEC4_1; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8029AEC4_0();
extern "C" void _s8029AEC4_1();
extern "C" void f_8029AEC4() {}
