// 0x8021CE00 FadeSquare::FadeSquare(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lis 4,-27018; lis 3,-32692; ori 4,4,24810; addi 3,3,-27556; bl _s8021CE00_0; stw 3,0xc(30); mr 3,30; bl _s8021CE00_1; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8021CE00_0();
extern "C" void _s8021CE00_1();
extern "C" void f_8021CE00() {}
