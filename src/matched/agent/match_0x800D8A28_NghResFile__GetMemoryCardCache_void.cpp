// 0x800D8A28 NghResFile::GetMemoryCardCache(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x190(31); lwz 0,0x10(3); cmpwi 0,0; bne 0f; lis 4,-32696; addi 4,4,25388; bl _s800D8A28_0; 0:; lwz 3,0x190(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800D8A28_0();
extern "C" void f_800D8A28() {}
