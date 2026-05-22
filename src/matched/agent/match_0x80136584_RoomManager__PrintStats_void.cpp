// 0x80136584 RoomManager::PrintStats(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); li 0,0; mr 30,3; lis 4,-32706; stw 0,0x8(1); addi 4,4,-11480; addi 3,13,-24588; bl _s80136584_0; lis 28,-32706; lwz 9,0x4(30); lis 29,-32706; lwz 0,0x8(9); stw 0,0x8(1); stw 0,0x10(1); b 2f; 0:; lwz 31,0x14(9); lwz 0,0x34(31); cmpwi 0,0; beq 1f; bl _s80136584_1; lhz 4,0x0(31); bl _s80136584_2; addi 4,29,-11440; bl _s80136584_3; mr 3,31; bl _s80136584_4; 1:; lwz 3,0x8(1); bl _s80136584_5; stw 3,0x8(1); 2:; lwz 0,0x4(30); addi 4,28,-11460; lwz 9,0x8(1); addi 3,13,-24588; li 11,1; stw 0,0x10(1); cmpw 9,0; bne 3f; li 11,0; 3:; cmpwi 11,0; bne 0b; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s80136584_0();
extern "C" void _s80136584_1();
extern "C" void _s80136584_2();
extern "C" void _s80136584_3();
extern "C" void _s80136584_4();
extern "C" void _s80136584_5();
extern "C" void f_80136584() {}
