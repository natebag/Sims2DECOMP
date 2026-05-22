// 0x80325058 EMovieMan::AllocateAndLoadResource(EFile (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,4; mr 29,3; lwz 9,0x28(30); mr 27,5; mr 26,6; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; mr 28,3; bl _s80325058_0; li 4,40; li 5,0; bl _s80325058_1; lwz 7,0xd20(29); mr 4,30; mr 6,27; mr 5,28; bl _s80325058_2; mr 29,3; stw 26,0x8(29); lwz 9,0x28(30); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); subf 4,28,3; subf 4,4,27; li 5,1; lha 3,0x28(9); lwz 0,0x2c(9); add 3,30,3; mtspr 8,0; blrl; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80325058_0();
extern "C" void _s80325058_1();
extern "C" void _s80325058_2();
extern "C" void f_80325058() {}
