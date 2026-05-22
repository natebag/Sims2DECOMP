// 0x80361D80 EStringTableNoCase::FreeTable(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 30,0x14(31); cmpwi 30,0; bne 0f; li 0,1; stw 30,0x10(31); stw 0,0xc(31); bl _s80361D80_0; lwz 4,0x8(31); bl _s80361D80_1; stw 30,0x8(31); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80361D80_0();
extern "C" void _s80361D80_1();
extern "C" void f_80361D80() {}
