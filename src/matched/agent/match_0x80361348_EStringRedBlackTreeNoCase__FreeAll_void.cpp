// 0x80361348 EStringRedBlackTreeNoCase::FreeAll(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 31,0x0(29); b 1f; 0:; lwz 30,0x18(31); bl _s80361348_0; mr 4,30; bl _s80361348_1; lwz 31,0x10(31); 1:; li 0,1; cmpwi 31,0; bne 2f; li 0,0; 2:; cmpwi 0,0; bne 0b; mr 3,29; bl _s80361348_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80361348_0();
extern "C" void _s80361348_1();
extern "C" void _s80361348_2();
extern "C" void f_80361348() {}
