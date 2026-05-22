// 0x800D2CC0 MemoryCardCache::GetSection(NghLayout (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 27,5; lwz 0,0x8(29); mr 30,6; mr 28,7; li 3,1; cmpwi 0,0; beq 2f; mr 3,4; mr 4,30; bl _s800D2CC0_0; lwz 11,0x4(29); cmpwi 11,0; beq 1f; rlwinm 9,3,2,0,29; lwzx 10,9,11; mr 26,9; cmpwi 10,0; beq 1f; mr 31,28; cmpwi 30,0; beq 0f; lis 9,-32696; lwz 11,0x6330(9); lwz 0,0x20(11); cmpw 30,0; beq 0f; lwz 9,0x4(10); lwz 0,0xc(10); add 0,0,9; cmplw 31,0; ble 0f; mr 31,0; mr 5,28; mr 3,27; li 4,0; bl _s800D2CC0_1; 0:; lwz 9,0x4(29); mr 3,27; mr 5,31; lwzx 4,26,9; crxor 6,6,6; bl _s800D2CC0_2; li 3,0; b 2f; 1:; li 3,3; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800D2CC0_0();
extern "C" void _s800D2CC0_1();
extern "C" void _s800D2CC0_2();
extern "C" void f_800D2CC0() {}
