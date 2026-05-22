// 0x80307528 ETweak::ETweak(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 29,0; addi 9,30,12; li 28,1; stw 29,0x4(9); addi 3,30,24; stw 29,0xc(30); stw 28,0x8(9); bl _s80307528_0; addi 3,30,32; bl _s80307528_1; addi 9,30,36; addi 3,30,48; stw 29,0x4(9); stw 29,0x24(30); stw 28,0x8(9); bl _s80307528_2; lis 9,-32702; stw 29,0x8(30); lfs f0,-1276(9); mr 3,30; stw 29,0x1c(30); stfs f0,0x0(30); stfs f0,0x4(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80307528_0();
extern "C" void _s80307528_1();
extern "C" void _s80307528_2();
extern "C" void f_80307528() {}
