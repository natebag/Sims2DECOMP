// 0x80361D3C EStringTableNoCase::PreGrowTable(int) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; b 1f; 0:; mr 3,31; bl _s80361D3C_0; 1:; lwz 0,0xc(31); cmplw 0,30; blt 0b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80361D3C_0();
extern "C" void f_80361D3C() {}
