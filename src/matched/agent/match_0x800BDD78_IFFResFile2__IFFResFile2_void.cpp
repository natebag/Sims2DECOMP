// 0x800BDD78 IFFResFile2::IFFResFile2(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s800BDD78_0; addi 3,30,16; bl _s800BDD78_1; lis 9,-32698; lis 11,-32698; li 0,0; addi 9,9,-2600; addi 11,11,-2576; li 10,-1; stw 9,0x134(30); mr 3,30; stw 11,0xc(30); stw 10,0x13c(30); stw 0,0x14c(30); stw 0,0x138(30); stw 0,0x140(30); stw 0,0x144(30); stw 0,0x148(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800BDD78_0();
extern "C" void _s800BDD78_1();
extern "C" void f_800BDD78() {}
