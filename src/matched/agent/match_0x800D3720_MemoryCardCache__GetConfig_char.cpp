// 0x800D3720 MemoryCardCache::GetConfig(char (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; lwz 0,0xc(31); mr 29,5; mr 30,6; cmpwi 0,0; bne 1f; lwz 0,0x0(31); cmpwi 0,0; bne 0f; bl _s800D3720_0; li 4,8192; li 5,64; li 6,0; li 7,0; bl _s800D3720_1; cmpwi 3,0; stw 3,0x0(31); li 3,2; beq 2f; 0:; mr 4,30; mr 3,31; bl _s800D3720_2; cmpwi 3,0; beq 1f; li 3,1; b 2f; 1:; lwz 4,0x0(31); mr 3,28; mr 5,29; crxor 6,6,6; bl _s800D3720_3; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800D3720_0();
extern "C" void _s800D3720_1();
extern "C" void _s800D3720_2();
extern "C" void _s800D3720_3();
extern "C" void f_800D3720() {}
