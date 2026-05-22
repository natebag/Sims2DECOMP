// 0x8029AF8C AptDisplayList::AptDisplayList(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,4; lwz 3,-23020(13); bl _s8029AF8C_0; bl _s8029AF8C_1; stw 3,0x0(30); mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8029AF8C_0();
extern "C" void _s8029AF8C_1();
extern "C" void f_8029AF8C() {}
