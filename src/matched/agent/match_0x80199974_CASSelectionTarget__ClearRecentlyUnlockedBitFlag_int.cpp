// 0x80199974 CASSelectionTarget::ClearRecentlyUnlockedBitFlag(int) (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); li 0,0; mr 31,3; stb 0,0x8(1); mr. 29,4; blt 2f; lwz 0,0x8c(31); cmpw 29,0; bge 2f; lwz 10,-21476(13); li 4,1; addi 9,31,148; lwz 11,0x0(10); lbzx 27,9,29; lha 3,0x120(11); lwz 0,0x124(11); add 3,10,3; mtspr 8,0; blrl; mr 30,3; lwz 3,0x84(31); bl _s80199974_0; lwz 28,0x84(3); cmpwi 30,0; beq 1f; lwz 4,0x54c(31); mr 3,31; addi 5,1,16; bl _s80199974_1; cmpwi 3,0; beq 0f; lwz 9,0x0(30); lha 3,0x160(9); lwz 0,0x164(9); add 3,30,3; mtspr 8,0; blrl; lwz 5,0x10(1); mr 4,28; mr 6,27; bl _s80199974_2; b 1f; 0:; lwz 4,0x54c(31); mr 3,31; addi 5,1,20; bl _s80199974_3; cmpwi 3,0; beq 1f; lwz 9,0x0(30); lha 3,0x160(9); lwz 0,0x164(9); add 3,30,3; mtspr 8,0; blrl; lwz 5,0x14(1); mr 4,28; mr 6,27; bl _s80199974_4; 1:; addi 9,31,748; lbzx 0,9,29; rlwinm 0,0,0,30,28; stbx 0,9,29; stb 0,0x8(1); 2:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s80199974_0();
extern "C" void _s80199974_1();
extern "C" void _s80199974_2();
extern "C" void _s80199974_3();
extern "C" void _s80199974_4();
extern "C" void f_80199974() {}
