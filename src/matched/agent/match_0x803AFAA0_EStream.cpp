// 0x803AFAA0 EStream (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,0,2,0,29; cmplwi 4,128; ble 0f; bl _s803AFAA0_0; b 1f; 0:; bl _s803AFAA0_1; 1:; add 0,27,31; stw 31,0x0(28); stw 0,0xc(28); stw 30,0x4(28); lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48; blr; stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); lis 9,-32698; addi 30,1,8; addi 9,9,24312; stw 3,0xc(1); stw 9,0x8(1); addi 3,1,24; stw 5,0x8(30); mr 5,4; mr 4,30; bl _s803AFAA0_2; mr 3,30; li 4,2; bl _s803AFAA0_3; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40; blr; stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); lis 9,-32698; addi 30,1,8; addi 9,9,24312; stw 3,0xc(1); stw 9,0x8(1); addi 3,1,24; stw 4,0x8(30); mr 4,30; bl _s803AFAA0_4; mr 29,3; li 4,2; mr 3,30; bl _s803AFAA0_5; mr 3,29; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s803AFAA0_0();
extern "C" void _s803AFAA0_1();
extern "C" void _s803AFAA0_2();
extern "C" void _s803AFAA0_3();
extern "C" void _s803AFAA0_4();
extern "C" void _s803AFAA0_5();
extern "C" void f_803AFAA0() {}
