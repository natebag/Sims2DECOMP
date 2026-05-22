// 0x800D2E7C MemoryCardCache::CacheNghSection(NghLayout (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,3; mr 27,4; mr 31,5; mr 30,7; mr. 26,6; beq 0f; lis 9,-32696; lwz 11,0x6330(9); lwz 0,0x20(11); cmpw 26,0; bne 1f; 0:; mr 4,26; mr 3,27; bl _s800D2E7C_0; mulli 9,3,24; lwz 0,0x4(27); mr 3,28; mr 4,27; mr 5,31; mr 6,26; add 9,9,0; lwz 7,0x4(9); b 7f; 1:; lwz 0,0x14(28); cmpwi 0,0; beq 2f; mr 3,31; bl _s800D2E7C_1; addi 3,31,4; bl _s800D2E7C_2; addi 3,31,8; bl _s800D2E7C_3; addi 3,31,12; bl _s800D2E7C_4; addi 3,31,16; bl _s800D2E7C_5; addi 3,31,20; bl _s800D2E7C_6; addi 3,31,24; bl _s800D2E7C_7; 2:; lwz 9,0xc(31); lwz 0,0x4(31); lwz 11,0x14(28); add 29,9,0; cmpwi 11,0; bne 6f; cmpwi 29,0; beq 3f; cmplw 29,30; ble 4f; 3:; li 3,4; b 8f; 4:; lwz 30,0x10(31); mr 3,31; stw 11,0x10(31); mr 4,29; bl _s800D2E7C_8; cmpw 30,3; stw 30,0x10(31); li 0,-4; bne 5f; li 0,1; 5:; cmpwi 0,1; li 3,4; bne 8f; 6:; mr 3,28; mr 4,27; mr 5,31; mr 6,26; mr 7,29; 7:; bl _s800D2E7C_9; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800D2E7C_0();
extern "C" void _s800D2E7C_1();
extern "C" void _s800D2E7C_2();
extern "C" void _s800D2E7C_3();
extern "C" void _s800D2E7C_4();
extern "C" void _s800D2E7C_5();
extern "C" void _s800D2E7C_6();
extern "C" void _s800D2E7C_7();
extern "C" void _s800D2E7C_8();
extern "C" void _s800D2E7C_9();
extern "C" void f_800D2E7C() {}
