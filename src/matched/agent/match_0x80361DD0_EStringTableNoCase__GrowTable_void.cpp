// 0x80361DD0 EStringTableNoCase::GrowTable(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 4,0xc(30); rlwinm 4,4,1,0,30; bl _s80361DD0_0; lwz 31,0x0(30); cmpwi 31,0; beq 1f; 0:; lwz 4,0xc(31); mr 3,30; bl _s80361DD0_1; lwz 9,0x8(30); rlwinm 3,3,2,0,29; lwzx 0,9,3; stw 0,0x8(31); stwx 31,9,3; lwz 31,0x4(31); cmpwi 31,0; bne 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80361DD0_0();
extern "C" void _s80361DD0_1();
extern "C" void f_80361DD0() {}
