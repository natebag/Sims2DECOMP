// 0x801302B0 cXPortalImpl::Pickup(void) (476 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 26,0x80(1); stw 0,0x9c(1); mr 26,3; lwz 31,-21488(13); lwz 9,0x0(26); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x10(11); lwz 0,0x14(11); add 3,10,3; mtspr 8,0; blrl; mr. 28,3; beq 4f; addi 27,1,72; 0:; lwz 9,0x0(28); li 4,11; lwz 3,0x0(9); bl _s801302B0_0; mr 30,3; lwz 11,0x4(30); lwz 9,0x4(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; lwz 9,0x0(30); lwz 11,0x0(9); lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x2a0(9); lwz 0,0x2a4(9); add 3,10,3; mtspr 8,0; blrl; mr. 29,3; beq 3f; lwz 9,0x0(30); lwz 30,0x0(9); lwz 11,0x4(30); addi 30,30,104; lwz 9,0x4(11); lwz 0,0x354(9); lha 3,0x350(9); mtspr 8,0; add 3,11,3; blrl; mr 5,3; mr 4,30; addi 3,1,8; bl _s801302B0_1; lwz 9,0x0(31); addi 4,1,8; lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; lwz 9,0x0(31); addi 30,1,16; mr 3,30; addi 5,1,8; lha 4,0xa8(9); lwz 0,0xac(9); add 4,31,4; mtspr 8,0; blrl; mr 3,30; mr 4,29; bl _s801302B0_2; cmpwi 3,0; beq 1f; mr 5,29; li 4,1; mr 3,30; bl _s801302B0_3; mr 4,30; mr 3,27; bl _s801302B0_4; lwz 9,0x0(31); addi 4,1,8; mr 5,27; lha 3,0xb0(9); lwz 0,0xb4(9); add 3,31,3; mtspr 8,0; blrl; 1:; mr 3,30; li 4,2; bl _s801302B0_5; 2:; addi 3,1,8; li 4,2; bl _s801302B0_6; 3:; lwz 9,0x4(28); lha 3,0x18(9); lwz 0,0x1c(9); add 3,28,3; mtspr 8,0; blrl; mr. 28,3; bne 0b; 4:; lwz 3,0x0(26); bl _s801302B0_7; lwz 9,0x0(26); lwz 11,0x0(9); lwz 3,0x58(11); bl _s801302B0_8; lwz 0,0x9c(1); mtspr 8,0; lmw 26,0x80(1); addi 1,1,152"
extern "C" void _s801302B0_0();
extern "C" void _s801302B0_1();
extern "C" void _s801302B0_2();
extern "C" void _s801302B0_3();
extern "C" void _s801302B0_4();
extern "C" void _s801302B0_5();
extern "C" void _s801302B0_6();
extern "C" void _s801302B0_7();
extern "C" void _s801302B0_8();
extern "C" void f_801302B0() {}
