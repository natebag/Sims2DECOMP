// 0x80239D40 EmitterSpr3d::CreateCameraFollowXY(char (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; bl _s80239D40_0; mr 30,3; cmpwi 30,-1; beq 0f; mr 3,31; bl _s80239D40_1; li 0,0; mr 8,3; lis 4,-32732; lis 5,-32732; lis 6,-32732; li 9,0; li 10,0; stw 0,0xc(1); stw 0,0x8(1); li 7,0; addi 4,4,-28112; addi 5,5,-29384; addi 6,6,-25776; mr 3,31; bl _s80239D40_2; mr 3,31; bl _s80239D40_3; mr 10,3; lwz 11,0x88(10); mr 3,30; lwz 0,0x108(11); oris 0,0,256; stw 0,0x108(11); lwz 9,0x88(10); lwz 0,0x108(9); oris 0,0,16; stw 0,0x108(9); lwz 11,0x88(10); lwz 0,0x108(11); rlwinm 0,0,0,28,25; stw 0,0x108(11); lwz 9,0x50(10); rlwinm 9,9,0,19,17; stw 9,0x50(10); 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80239D40_0();
extern "C" void _s80239D40_1();
extern "C" void _s80239D40_2();
extern "C" void _s80239D40_3();
extern "C" void f_80239D40() {}
