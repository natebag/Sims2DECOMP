// 0x8001E9AC EStream (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; bl _s8001E9AC_0; li 6,0; li 7,0; mr 4,29; li 5,16; bl _s8001E9AC_1; mr 30,3; mr 5,29; li 4,0; bl _s8001E9AC_2; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8001E9AC_3; mr 4,30; bl _s8001E9AC_4; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; addi 3,3,1048; blr; addi 3,3,1084; blr; addi 3,3,1060; blr; addi 3,3,1060; blr; lwz 10,0x0(4); addi 11,3,1084; lwz 0,0x8(4); lwz 9,0x4(4); stw 10,0x43c(3); stw 0,0x8(11); stw 9,0x4(11); blr; addi 3,3,16; blr; lfs f1,0x448(3); blr; lfs f1,0x450(3); blr; stfs f1,0x450(3); blr; lwz 3,0x8(3); blr; lfs f1,0x44c(3)"
extern "C" void _s8001E9AC_0();
extern "C" void _s8001E9AC_1();
extern "C" void _s8001E9AC_2();
extern "C" void _s8001E9AC_3();
extern "C" void _s8001E9AC_4();
extern "C" void f_8001E9AC() {}
