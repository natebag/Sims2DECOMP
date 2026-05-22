// 0x800D2AB4 MemoryCardCache::Init(NghLayout (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 28,4; lwz 9,0x10(31); cmpwi 9,0; beq 0f; li 3,0; b 6f; 0:; lwz 0,0x4(31); stw 9,0xc(31); cmpwi 0,0; stw 9,0x8(31); stw 28,0x18(31); beq 4f; lwz 0,0xc(28); li 29,0; cmpw 29,0; bge 3f; li 27,0; li 30,0; 1:; lwz 9,0x4(31); lwzx 0,30,9; cmpwi 0,0; beq 2f; bl _s800D2AB4_0; lwz 9,0x4(31); lwzx 4,30,9; bl _s800D2AB4_1; lwz 9,0x4(31); stwx 27,30,9; 2:; lwz 0,0xc(28); addi 29,29,1; addi 30,30,4; cmpw 29,0; blt 1b; 3:; bl _s800D2AB4_2; lwz 4,0x4(31); bl _s800D2AB4_3; li 0,0; stw 0,0x4(31); 4:; lwz 30,0xc(28); rlwinm 30,30,2,0,29; bl _s800D2AB4_4; mr 4,30; li 5,4; li 6,0; li 7,0; bl _s800D2AB4_5; mr 0,3; mr 5,30; stw 0,0x4(31); li 4,0; bl _s800D2AB4_6; lwz 0,0x0(31); cmpwi 0,0; bne 5f; bl _s800D2AB4_7; li 4,8192; li 5,64; li 6,0; li 7,0; bl _s800D2AB4_8; cmpwi 3,0; stw 3,0x0(31); bne 5f; li 3,2; b 6f; 5:; li 0,1; li 3,0; stw 0,0x10(31); 6:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800D2AB4_0();
extern "C" void _s800D2AB4_1();
extern "C" void _s800D2AB4_2();
extern "C" void _s800D2AB4_3();
extern "C" void _s800D2AB4_4();
extern "C" void _s800D2AB4_5();
extern "C" void _s800D2AB4_6();
extern "C" void _s800D2AB4_7();
extern "C" void _s800D2AB4_8();
extern "C" void f_800D2AB4() {}
