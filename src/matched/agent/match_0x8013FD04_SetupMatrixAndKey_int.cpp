// 0x8013FD04 SetupMatrixAndKey(int, (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lwz 30,-21476(13); mr 29,4; mr 4,3; mr 31,5; lwz 9,0x0(30); mr 27,6; lwz 0,0xbc(9); lha 3,0xb8(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(30); mr 28,3; mr 4,29; lwz 0,0xbc(9); lha 3,0xb8(9); mtspr 8,0; add 3,30,3; blrl; mr 3,28; bl _s8013FD04_0; stw 3,0x0(31); mr 4,29; stw 29,0x0(27); lwz 11,0x0(31); lwz 9,0x0(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,2; bgt 0f; lwz 11,0x0(31); li 5,3; lwz 4,0x0(27); lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x0(31); lwz 4,0x0(27); lwz 9,0x0(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8013FD04_0();
extern "C" void f_8013FD04() {}
