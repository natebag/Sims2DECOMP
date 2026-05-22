// 0x800D2D9C MemoryCardCache::PutSection(NghLayout (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,5; lwz 0,0x10(31); mr 3,4; mr 4,6; mr 29,7; cmpwi 0,0; beq 0f; lwz 0,0x4(31); cmpwi 0,0; bne 1f; 0:; li 3,1; b 4f; 1:; bl _s800D2D9C_0; lwz 9,0x4(31); rlwinm 30,3,2,0,29; lwzx 0,30,9; cmpwi 0,0; beq 2f; bl _s800D2D9C_1; lwz 9,0x4(31); lwzx 4,30,9; bl _s800D2D9C_2; lwz 9,0x4(31); li 0,0; stwx 0,30,9; 2:; bl _s800D2D9C_3; mr 4,29; li 5,64; li 6,0; li 7,0; bl _s800D2D9C_4; lwz 9,0x4(31); stwx 3,30,9; lwz 11,0x4(31); lwzx 3,30,11; cmpwi 3,0; beq 3f; mr 4,28; mr 5,29; crxor 6,6,6; bl _s800D2D9C_5; li 0,1; li 3,0; stw 0,0x8(31); b 4f; 3:; li 3,2; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800D2D9C_0();
extern "C" void _s800D2D9C_1();
extern "C" void _s800D2D9C_2();
extern "C" void _s800D2D9C_3();
extern "C" void _s800D2D9C_4();
extern "C" void _s800D2D9C_5();
extern "C" void f_800D2D9C() {}
