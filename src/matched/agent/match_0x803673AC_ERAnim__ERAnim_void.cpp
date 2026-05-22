// 0x803673AC ERAnim::ERAnim(void) (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 29,0x1c(1); stw 0,0x34(1); mr 30,3; addi 29,30,80; bl _s803673AC_0; lis 9,-32697; addi 3,30,52; addi 9,9,-9144; stw 9,0x0(30); bl _s803673AC_1; addi 3,30,68; bl _s803673AC_2; mr 3,29; bl _s803673AC_3; lis 9,-32697; lis 10,-32702; addi 9,9,-9000; lis 6,-32702; stw 9,0x10(29); addi 11,30,100; li 8,251; li 7,3; lfs f0,0x3268(10); li 0,0; li 9,1; lis 10,-32702; stfs f0,0x64(30); lis 5,-32702; lis 4,-32702; lis 29,-32702; lfs f31,0x326c(6); addi 3,30,136; stw 8,0x8(11); stb 7,0xc(11); stb 0,0xd(11); stb 9,0xe(11); stfs f31,0x4(11); lfs f13,0x3270(10); stfs f13,0x14(11); stfs f13,0x10(11); lfs f0,0x3274(5); stfs f0,0x1c(11); lfs f13,0x3278(4); stfs f13,0x20(11); lfs f0,0x327c(29); stfs f0,0x18(11); bl _s803673AC_4; addi 3,30,148; bl _s803673AC_5; addi 9,1,8; li 11,0; stfs f31,0x8(9); addi 8,30,40; stfs f31,0x4(9); addi 7,30,28; stfs f31,0x8(1); mr 3,30; stw 11,0x18(30); lwz 11,0x8(9); lwz 0,0x8(1); lwz 10,0x4(9); stw 0,0x28(30); stw 11,0x8(8); stw 10,0x4(8); lwz 9,-25836(13); lwz 0,0x28(30); addi 9,9,1; stw 0,0x1c(30); stw 11,0x8(7); stw 10,0x4(7); stw 9,-25836(13); lwz 0,0x34(1); mtspr 8,0; lmw 29,0x1c(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s803673AC_0();
extern "C" void _s803673AC_1();
extern "C" void _s803673AC_2();
extern "C" void _s803673AC_3();
extern "C" void _s803673AC_4();
extern "C" void _s803673AC_5();
extern "C" void f_803673AC() {}
