// 0x800D29DC MemoryCardCache::GetMemoryUsage(NghLayout (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 30,4; lwz 0,0x4(29); li 27,0; cmpwi 0,0; beq 2f; lwz 0,0xc(30); li 31,0; cmpw 27,0; bge 2f; li 28,0; 0:; lwz 9,0x4(29); lwzx 0,28,9; cmpwi 0,0; beq 1f; mr 3,29; mr 4,30; mr 5,31; bl _s800D29DC_0; add 27,27,3; 1:; lwz 0,0xc(30); addi 31,31,1; addi 28,28,4; cmpw 31,0; blt 0b; 2:; mr 3,27; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800D29DC_0();
extern "C" void f_800D29DC() {}
