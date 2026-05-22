// 0x800B4ED8 CTilePt::GetTileDirection(CTilePt (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,3; mr 31,4; bl _s800B4ED8_0; cmpwi 3,0; li 3,8; bne 7f; mr 3,28; bl _s800B4ED8_1; mr 30,3; mr 3,28; bl _s800B4ED8_2; mr 29,3; mr 3,31; bl _s800B4ED8_3; subf 26,30,3; mr 3,31; bl _s800B4ED8_4; subf 27,29,3; mr 3,31; bl _s800B4ED8_5; mr 29,3; mr 3,31; bl _s800B4ED8_6; mr 30,3; mr 3,28; bl _s800B4ED8_7; mr 31,3; mr 3,28; bl _s800B4ED8_8; srawi 0,26,31; subf. 9,3,30; xor 10,0,26; subf 10,0,10; srawi 0,27,31; xor 8,0,27; subf 8,0,8; blt 0f; rlwinm 0,9,1,31,31; add 0,9,0; b 1f; 0:; subf 0,30,3; rlwinm 9,0,1,31,31; add 0,0,9; 1:; srawi 11,0,1; subf. 9,31,29; blt 2f; rlwinm 0,9,1,31,31; add 0,9,0; b 3f; 2:; subf 0,29,31; rlwinm 9,0,1,31,31; add 0,0,9; 3:; srawi 0,0,1; cmpw 10,8; bge 4f; cmpw 10,11; bgt 4f; cmpw 10,0; bgt 4f; not 0,27; rlwinm 3,0,1,31,31; b 7f; 4:; cmpw 8,10; bge 5f; cmpw 8,11; bgt 5f; cmpw 8,0; bgt 5f; cmpwi 26,0; li 3,3; bge 7f; li 3,2; b 7f; 5:; cmpw 11,10; bge 6f; cmpw 11,8; bge 6f; cmpw 11,0; bge 6f; cmpw 29,31; li 3,5; bge 7f; li 3,4; b 7f; 6:; cmpw 30,3; li 3,6; bge 7f; li 3,7; 7:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800B4ED8_0();
extern "C" void _s800B4ED8_1();
extern "C" void _s800B4ED8_2();
extern "C" void _s800B4ED8_3();
extern "C" void _s800B4ED8_4();
extern "C" void _s800B4ED8_5();
extern "C" void _s800B4ED8_6();
extern "C" void _s800B4ED8_7();
extern "C" void _s800B4ED8_8();
extern "C" void f_800B4ED8() {}
