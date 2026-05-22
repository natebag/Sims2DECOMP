// 0x80152D74 XRoute::XRoute(cXObject (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 30,3; li 0,0; stw 0,0x0(30); addi 9,30,8; stw 0,0x4(30); mr 27,4; stw 0,0x4(9); mr 29,5; mr 28,6; addi 3,30,16; bl _s80152D74_0; mr 3,30; mr 4,27; mr 5,29; mr 6,28; bl _s80152D74_1; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s80152D74_0();
extern "C" void _s80152D74_1();
extern "C" void f_80152D74() {}
