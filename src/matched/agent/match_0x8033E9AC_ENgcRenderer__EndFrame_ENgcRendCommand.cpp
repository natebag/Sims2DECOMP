// 0x8033E9AC ENgcRenderer::EndFrame(ENgcRendCommand (656 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 31,3; lwz 28,0x4(4); lhz 5,0x368(31); li 3,0; lhz 6,0x36a(31); li 4,0; bl _s8033E9AC_0; lhz 3,0x368(31); li 6,1; lhz 4,0x36a(31); li 5,4; rlwinm 3,3,31,1,31; rlwinm 4,4,31,1,31; bl _s8033E9AC_1; lwz 3,0x4650(31); li 4,0; bl _s8033E9AC_2; lwz 3,0x34c(31); lis 4,-32716; lis 5,-32716; addi 4,4,-19344; addi 5,5,-19280; bl _s8033E9AC_3; lwz 3,0x4d8(31); bl _s8033E9AC_4; lwz 11,0x4d8(31); li 10,1; li 8,7; li 4,0; lwz 0,0x6cc(11); oris 0,0,32768; stw 0,0x6cc(11); lwz 9,0x4d8(31); lwz 0,0x6cc(9); stb 10,0x3b4(9); oris 0,0,32768; stw 8,0x3b0(9); ori 0,0,64; stb 10,0x3ac(9); stw 0,0x6cc(9); lwz 3,0x4d8(31); bl _s8033E9AC_5; li 3,1; bl _s8033E9AC_6; li 3,1; bl _s8033E9AC_7; lis 9,-32702; lfs f0,-26184(13); lfs f13,0x1d30(9); lwz 4,0x360(31); fcmpu 0,f0,f13; blt 0f; lis 9,-32702; fmr f13,f0; lfs f12,0x1d34(9); fcmpu 0,f0,f12; ble 0f; fmr f13,f12; 0:; li 0,7; lis 9,-32702; mtspr 9,0; rlwinm 29,4,0,24,31; stfs f13,-26184(13); fmr f11,f13; lfd f10,0x1d38(9); li 10,0; addi 4,31,894; addi 30,1,16; addi 7,31,918; lis 6,17200; addi 8,1,8; 1:; lbzx 0,7,10; mr 11,9; xoris 0,0,32768; stw 0,0x24(1); stw 6,0x20(1); lfd f0,0x20(1); fsub f0,f0,f10; frsp f0,f0; fmuls f0,f0,f11; fmr f13,f0; fctiwz f12,f13; stfd f12,0x20(1); lwz 11,0x24(1); stbx 11,8,10; addi 10,10,1; bdnz 1b; lbz 3,0x37d(31); li 5,1; addi 6,1,8; bl _s8033E9AC_8; lwz 0,0x3ac(31); mr 3,30; lwz 4,0x3b0(31); stw 0,0x10(1); bl _s8033E9AC_9; lwz 9,-26176(13); li 0,0; stw 0,0x18(1); cmpwi 9,0; stw 0,0x14(1); beq 3f; lis 3,-32690; li 4,-1; lwz 9,-25824(3); li 30,1; addi 3,3,-25824; lha 0,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; lwz 0,0x34c(31); mr 4,29; stw 28,-26140(13); mr 3,0; stw 0,-26144(13); bl _s8033E9AC_10; bl _s8033E9AC_11; bl _s8033E9AC_12; addi 4,1,20; addi 5,1,24; bl _s8033E9AC_13; bl _s8033E9AC_14; cmpwi 3,0; bne 2f; li 30,0; 2:; lwz 3,0x18(1); bl _s8033E9AC_15; li 0,1; mr 3,30; stw 0,-26152(13); bl _s8033E9AC_16; lwz 9,0x340(31); addi 11,31,836; addi 9,9,1; rlwinm 0,9,1,31,31; add 0,9,0; rlwinm 0,0,0,0,30; subf 9,0,9; stw 9,0x340(31); rlwinm 9,9,2,0,29; lwzx 0,11,9; stw 0,0x34c(31); b 4f; 3:; bl _s8033E9AC_17; lwz 3,0x34c(31); mr 4,29; bl _s8033E9AC_18; mr 3,28; bl _s8033E9AC_19; 4:; lwz 3,0x4d8(31); bl _s8033E9AC_20; li 0,1; stw 0,0x510(31); lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"
extern "C" void _s8033E9AC_0();
extern "C" void _s8033E9AC_1();
extern "C" void _s8033E9AC_2();
extern "C" void _s8033E9AC_3();
extern "C" void _s8033E9AC_4();
extern "C" void _s8033E9AC_5();
extern "C" void _s8033E9AC_6();
extern "C" void _s8033E9AC_7();
extern "C" void _s8033E9AC_8();
extern "C" void _s8033E9AC_9();
extern "C" void _s8033E9AC_10();
extern "C" void _s8033E9AC_11();
extern "C" void _s8033E9AC_12();
extern "C" void _s8033E9AC_13();
extern "C" void _s8033E9AC_14();
extern "C" void _s8033E9AC_15();
extern "C" void _s8033E9AC_16();
extern "C" void _s8033E9AC_17();
extern "C" void _s8033E9AC_18();
extern "C" void _s8033E9AC_19();
extern "C" void _s8033E9AC_20();
extern "C" void f_8033E9AC() {}
