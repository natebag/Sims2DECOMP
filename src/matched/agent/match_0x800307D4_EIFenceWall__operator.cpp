// 0x800307D4 EIFenceWall::operator (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s800307D4_0; mr 4,30; li 5,16; li 6,0; li 7,0; bl _s800307D4_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800307D4_0();
extern "C" void _s800307D4_1();
extern "C" void f_800307D4() {}
