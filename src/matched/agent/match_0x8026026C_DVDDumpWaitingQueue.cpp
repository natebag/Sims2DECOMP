// 0x8026026C DVDDumpWaitingQueue (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32700; stw 0,0x4(1); crxor 6,6,6; stwu 1,-24(1); stw 31,0x14(1); addi 31,3,-14184; addi 3,31,236; stw 30,0x10(1); stw 29,0xc(1); stw 28,0x8(1); bl _s8026026C_0; lis 3,-32694; addi 30,3,-17096; li 29,0; 0:; addi 4,29,0; crxor 6,6,6; addi 3,31,272; bl _s8026026C_1; lwz 0,0x0(30); cmplw 0,30; bne 1f; addi 3,13,-27716; crxor 6,6,6; bl _s8026026C_2; b 6f; 1:; addi 3,13,-27708; crxor 6,6,6; bl _s8026026C_3; lwz 28,0x0(30); b 5f; 2:; lwz 0,0x8(28); addi 4,28,0; addi 3,31,288; crxor 6,6,6; rlwinm 0,0,2,0,29; add 5,31,0; lwz 5,0xac(5); bl _s8026026C_4; lwz 0,0x8(28); cmplwi 0,1; bne 3f; lwz 4,0x10(28); addi 3,31,312; lwz 5,0x14(28); crxor 6,6,6; lwz 6,0x18(28); bl _s8026026C_5; b 4f; 3:; addi 3,13,-27708; crxor 6,6,6; bl _s8026026C_6; 4:; lwz 28,0x0(28); 5:; cmplw 28,30; bne 2b; 6:; addi 29,29,1; cmplwi 29,4; addi 30,30,8; blt 0b; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); lwz 29,0xc(1); lwz 28,0x8(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8026026C_0();
extern "C" void _s8026026C_1();
extern "C" void _s8026026C_2();
extern "C" void _s8026026C_3();
extern "C" void _s8026026C_4();
extern "C" void _s8026026C_5();
extern "C" void _s8026026C_6();
extern "C" void f_8026026C() {}
