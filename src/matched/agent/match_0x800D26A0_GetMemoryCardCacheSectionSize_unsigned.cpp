// 0x800D26A0 GetMemoryCardCacheSectionSize(unsigned (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,-32056(13); bl _s800D26A0_0; lis 4,-32696; mr 5,30; addi 4,4,25388; bl _s800D26A0_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800D26A0_0();
extern "C" void _s800D26A0_1();
extern "C" void f_800D26A0() {}
